/*
 * myapp.h
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#ifndef MYAPP_H_
#define MYAPP_H_

#include "application.h"
#include "shader.h"
#include "program.h"
#include "cubegeometry.h"
#include "material.h"
#include "scene.h"
#include "object.h"

class myapp : public gla::application
{
public:
    myapp(int argc, char** argv);

private:
    void startup();
    void shutdown();
    void resize(int w, int h);
    void update(float delta);
    void mouse_motion(SDL_MouseMotionEvent* event);
    void event(SDL_Event* event);

    gltools::program program;
    cube_geometry cube_geom;
    scene myscene;

    object* cube;
    object* cube2;
    object* cube3;


    glm::mat4 projection;
    glm::mat4 view;

    float rotation = 0.f;
    bool mouse_button_down = false;
};

#endif /* MYAPP_H_ */
