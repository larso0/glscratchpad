/*
 * myapp.h
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#ifndef MYAPP_H_
#define MYAPP_H_

#include "application.h"
#include "scene/shader.h"
#include "scene/shader_program.h"
#include "scene/cubegeometry.h"
#include "mymaterial.h"
#include "scene/node.h"
#include "scene/object.h"
#include "scene/pointlight.h"

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

    scene::shader_program program;
    scene::cube_geometry* cube_geom = nullptr;
    mymaterial* material = nullptr;
    scene::node myscene;

    scene::object* cube = nullptr;
    scene::object* cube2 = nullptr;
    scene::object* cube3 = nullptr;
    scene::point_light* light = nullptr;

    glm::mat4 projection;
    glm::mat4 view;

    float rotation = 0.f;
    bool mouse_button_down = false;
};

#endif /* MYAPP_H_ */
