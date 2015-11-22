/*
 * application.h
 *
 *  Created on: 27. sep. 2015
 *      Author: larso
 */

#ifndef SRC_APPLICATION_H_
#define SRC_APPLICATION_H_

#include <SDL2/SDL.h>
#include "gl_includes.h"
#include <string>

namespace gla
{

class application
{
public:
    application(int argc, char** argv);
    virtual ~application();

    void run();

protected:
    int argc;
    char** argv;

    Uint32 sdl_init_flags;
    Uint32 window_flags;
    int gl_major_version, gl_minor_version;
    bool vsync_enabled;
    float current_time;

    void set_title(std::string title);
    void set_size(int w, int h);
    void set_position(int x, int y);
    void swap_buffers();
    void quit();

    const Uint8* keyboard_state();

    virtual void startup() = 0;
    virtual void shutdown() = 0;
    virtual void resize(int w, int h) = 0;
    virtual void update(float delta) = 0;
    virtual void event(SDL_Event* event) = 0;

private:
    int x, y;
    int width, height;
    std::string title;
    bool initialized;
    bool running;

    SDL_Window* window;
    SDL_GLContext gl_context;

    void init();
    void main_loop();
};

} /* namespace gla */

#endif /* SRC_APPLICATION_H_ */
