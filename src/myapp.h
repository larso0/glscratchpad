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

class myapp : public gla::application
{
public:
    myapp(int argc, char** argv);

private:
    void startup();
    void shutdown();
    void resize(int w, int h);
    void update(float delta);
    void event(SDL_Event* event);

    GLuint vao; //Vertex attribute object
    gltools::program program;

    int element_count = 36;
    glm::vec3 vertices[8] = {
            glm::vec3(-1.f, -1.f, 1.f),
            glm::vec3(1.f, -1.f, 1.f),
            glm::vec3(1.f, 1.f, 1.f),
            glm::vec3(-1.f, 1.f, 1.f),
            glm::vec3(-1.f, -1.f, -1.f),
            glm::vec3(1.f, -1.f, -1.f),
            glm::vec3(1.f, 1.f, -1.f),
            glm::vec3(-1.f, 1.f, -1.f)
    };
    GLshort indices[36] = {
            0, 1, 2, 2, 3, 0,
            3, 2, 6, 6, 7, 3,
            7, 6, 5, 5, 4, 7,
            4, 0, 3, 3, 7, 4,
            0, 1, 5, 5, 4, 0,
            1, 5, 6, 6, 2, 1
    };
    GLuint vertex_buffer;
    GLuint index_buffer;

    glm::mat4 projection;
    glm::mat4 view;
};

#endif /* MYAPP_H_ */
