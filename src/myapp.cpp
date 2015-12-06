/*
 * myapp.cpp
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#include "myapp.h"

using gltools::shader;

myapp::myapp(int argc, char** argv) :
    gla::application(argc, argv), cube(nullptr), cube2(nullptr), cube3(nullptr)
{
}

void myapp::startup()
{
    //SDL_ShowCursor(0);
    //SDL_SetRelativeMouseMode(SDL_TRUE);

    shader vshader("vshader.glsl", GL_VERTEX_SHADER);
    vshader.compile();
    if(!vshader.get_infolog().empty())
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Vertex shader infolog", vshader.get_infolog().c_str(), window);
    }

    shader fshader("fshader.glsl", GL_FRAGMENT_SHADER);
    fshader.compile();
    if(!fshader.get_infolog().empty())
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Fragment shader infolog", fshader.get_infolog().c_str(), window);
    }

    program.attach_shader(vshader);
    program.attach_shader(fshader);
    program.link();
    program.use();

    cube = new object(&cube_geom, &program);
    cube2 = new object(&cube_geom, &program);
    cube3 = new object(&cube_geom, &program);
    myscene.add(cube);
    cube->add(cube2);
    cube->add(cube3);
    cube2->scale(glm::vec3(0.5f, 2.f, 0.25f));
    cube2->translate(glm::vec3(1.5f, 0.f, 0.f));
    cube3->scale(glm::vec3(0.25f, 0.25f, 0.25f));
    cube3->translate(glm::vec3(-1.5f, 0.f, 0.f));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    view = glm::lookAt(glm::vec3(0.f, 1.f, 3.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
    glUniformMatrix4fv(program.get_uniform_location("view"), 1, GL_FALSE, glm::value_ptr(view));
}

void myapp::shutdown()
{
    delete cube;
    delete cube2;
    delete cube3;
}

void myapp::resize(int w, int h)
{
    glViewport(0, 0, w, h);
    projection = glm::perspective(glm::radians(60.f), (float)w/h, 0.1f, 100.f);
    GLint projection_location = program.get_uniform_location("projection");
    glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));
}

void myapp::update(float delta)
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myscene.render();
    swap_buffers();
}

void myapp::mouse_motion(SDL_MouseMotionEvent* event)
{
    if(mouse_button_down)
    {
        float sensitivity = 0.01;
        int x = event->xrel;
        int y = event->yrel;
        cube->rotate_euler(glm::vec3(sensitivity*y, sensitivity*x, 0.f));
    }
}

void myapp::event(SDL_Event* event)
{
    switch(event->type)
    {
    case SDL_MOUSEMOTION:
        mouse_motion(&event->motion);
        break;
    case SDL_MOUSEBUTTONDOWN:
        if(event->button.button == SDL_BUTTON_LEFT)
        {
            mouse_button_down = true;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if(event->button.button == SDL_BUTTON_LEFT)
        {
            mouse_button_down = false;
        }
        break;
    }
}

int main(int argc, char** argv)
{
    myapp app(argc, argv);
    app.run();
    return 0;
}
