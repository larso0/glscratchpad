/*
 * glapplication.cpp
 *
 *  Created on: 27. sep. 2015
 *      Author: larso
 */

#include "application.h"
#include <stdexcept>

namespace gla
{

application::application(int argc, char** argv) :
    argc(argc), argv(argv),
    sdl_init_flags(SDL_INIT_VIDEO),
    window_flags(SDL_WINDOW_RESIZABLE),
    gl_major_version(4), gl_minor_version(5),
    vsync_enabled(true),
    current_time(0.f),
    x(SDL_WINDOWPOS_UNDEFINED), y(SDL_WINDOWPOS_UNDEFINED),
    width(640), height(480),
    title("GLApplication"),
    initialized(false), running(false),
    window(nullptr), gl_context(nullptr)
{
}

application::~application()
{
    if(initialized)
    {
        SDL_GL_DeleteContext(gl_context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}

void application::set_title(std::string title)
{
    this->title = title;
    if(initialized)
    {
        SDL_SetWindowTitle(window, title.c_str());
    }
}

void application::set_size(int w, int h)
{
    width = w;
    height = h;
    if(initialized)
    {
        SDL_SetWindowSize(window, width, height);
    }
}

void application::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
    if(initialized)
    {
        SDL_SetWindowPosition(window, x, y);
    }
}

void application::swap_buffers()
{
    if(initialized)
    {
        SDL_GL_SwapWindow(window);
    }
}

void application::quit()
{
    running = false;
}

const Uint8* application::keyboard_state()
{
    return SDL_GetKeyboardState(NULL);
}

void application::init()
{
    int error = SDL_Init(sdl_init_flags);
    if(error)
    {
        std::string error(SDL_GetError());
        throw std::runtime_error("SDL_Init failed: " + error);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, gl_major_version);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, gl_minor_version);

    window = SDL_CreateWindow
            (
                title.c_str(),
                x, y,
                width, height,
                SDL_WINDOW_OPENGL | window_flags
            );
    if(window == nullptr)
    {
        std::string error(SDL_GetError());
        SDL_Quit();
        throw std::runtime_error("SDL_CreateWindow failed: " + error);
    }

    gl_context = SDL_GL_CreateContext(window);
    if(gl_context == nullptr)
    {
        std::string error(SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error("SDL_GL_CreateContext failed: " + error);
    }

    if(vsync_enabled)
    {
        error = SDL_GL_SetSwapInterval(1);
        if(error)
        {
            std::string error = "Warning: Unable to set VSync: " + std::string(SDL_GetError());
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Unable to set VSync", error.c_str(), window);
        }
    }

    glewExperimental = GL_TRUE;
    GLenum glewerror = glewInit();
    if(glewerror != GLEW_OK)
    {
        std::string errorstr((const char*)glewGetErrorString(error));
        throw std::runtime_error("Unable to initialize GLEW: " + errorstr);
    }

    initialized = true;
}

void application::main_loop()
{
    SDL_Event event;
    running = true;
    while(running)
    {
        float ntime = SDL_GetTicks()/1000.f;
        float delta = ntime - current_time;
        current_time = ntime;
        update(delta);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_WINDOWEVENT:
                if(event.window.event == SDL_WINDOWEVENT_RESIZED ||
                   event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    width = event.window.data1;
                    height = event.window.data2;
                    resize(width, height);
                }
                break;
            default:
                break;
            }
            this->event(&event);
        }
    }
}

void application::run()
{
    try
    {
        init();
        startup();
        resize(width, height);
        current_time = SDL_GetTicks()/1000.f;
        SDL_PumpEvents();
        SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
        main_loop();
        shutdown();
    }
    catch(const std::runtime_error& error)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                                 error.what(), nullptr);
    }
}

} /* namespace gla */
