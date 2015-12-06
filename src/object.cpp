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
    texture_coordinate(2),
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

    glGenVertexArrays(1, &vertex_attribute_object);
    geom->initialize();

    glBindVertexArray(vertex_attribute_object);

    glEnableVertexAttribArray(position);
    glBindBuffer(GL_ARRAY_BUFFER, geom->vertex_buffer());
    glVertexAttribPointer(position, 3, GL_FLOAT, false, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geom->index_buffer());

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
    glDrawElements(GL_TRIANGLES, geom->element_count(), GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
    scene_node::render();
}
