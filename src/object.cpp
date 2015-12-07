/*
 * object.cpp
 *
 *  Created on: 6. des. 2015
 *      Author: larso
 */

#include "object.h"
#include <stdexcept>

object::object(geometry* geom, gltools::program* program) :
    scene_node(),
    geom(geom),
    program(program),
    position(0),
    normal(1),
    uv(2),
    modelworld(0),
    view(1),
    projection(2),
    vertex_attribute_object(0)
{
    if(geom == nullptr)
    {
        throw std::invalid_argument("Geometry can not be a nullpointer.");
    }
    if(program == nullptr)
    {
        throw std::invalid_argument("Program can not be a nullpointer.");
    }

    program->use();
    glGenVertexArrays(1, &vertex_attribute_object);
    geom->initialize();

    glBindVertexArray(vertex_attribute_object);

    glBindBuffer(GL_ARRAY_BUFFER, geom->vertex_buffer());
    glEnableVertexAttribArray(position);
    glVertexAttribPointer(position, 3, GL_FLOAT, false, vertex::stride, (GLvoid*)vertex::position_offset);
    glEnableVertexAttribArray(normal);
    glVertexAttribPointer(normal, 3, GL_FLOAT, false, vertex::stride, (GLvoid*)vertex::normal_offset);
    glEnableVertexAttribArray(uv);
    glVertexAttribPointer(uv, 2, GL_FLOAT, false, vertex::stride, (GLvoid*)vertex::uv_offset);

    glBindVertexArray(0);
}

object::~object()
{
    glDeleteVertexArrays(1, &vertex_attribute_object);
}

void object::render()
{
    program->use();
    glUniformMatrix4fv(modelworld,
            1, GL_FALSE, glm::value_ptr(world_matrix));
    glBindVertexArray(vertex_attribute_object);
    glDrawArrays(GL_TRIANGLES, 0, geom->vertex_count());
    glBindVertexArray(0);
    scene_node::render();
}
