/*
 * myapp.cpp
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#include "myapp.h"

using gltools::shader;

myapp::myapp(int argc, char** argv) :
    gla::application(argc, argv),
    vao(0), vertex_buffer(0), index_buffer(0)
{
}

void myapp::startup()
{
    shader vshader("vshader.glsl", GL_VERTEX_SHADER);
    vshader.compile();

    shader fshader("fshader.glsl", GL_FRAGMENT_SHADER);
    fshader.compile();

    program.attach_shader(vshader);
    program.attach_shader(fshader);
    program.link();
    program.use();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    view = glm::lookAt(glm::vec3(0.f, 1.f, 3.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
    GLint modelview_location = program.get_uniform_location("modelview");
    glUniformMatrix4fv(modelview_location, 1, GL_FALSE, glm::value_ptr(view));
}

void myapp::shutdown()
{
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteBuffers(1, &index_buffer);
    glDeleteVertexArrays(1, &vao);
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
    glm::mat4 modelview;
    modelview = glm::rotate(modelview, current_time, glm::vec3(0.f, 1.f, 0.f));
    modelview = view * modelview;
    GLint modelview_location = program.get_uniform_location("modelview");
    glUniformMatrix4fv(modelview_location, 1, GL_FALSE, glm::value_ptr(modelview));

    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLint position_location = program.get_attribute_location("position");
    glEnableVertexAttribArray(position_location);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexAttribPointer(position_location, 3, GL_FLOAT, false, 0, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glDrawElements(GL_TRIANGLES, element_count, GL_UNSIGNED_SHORT, 0);
    swap_buffers();
}

void myapp::event(SDL_Event* event)
{
}

int main(int argc, char** argv)
{
    myapp app(argc, argv);
    app.run();
    return 0;
}
