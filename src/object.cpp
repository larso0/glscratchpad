/*
 * object.cpp
 *
 *  Created on: 6. des. 2015
 *      Author: larso
 */

#include "object.h"

object::object(geometry& geom, material& mater) :
    scene_node(),
    geom(geom),
    mater(mater),
    vertex_attribute_object(0)
{
    glGenVertexArrays(1, &vertex_attribute_object);
    geom.initialize();

    glBindVertexArray(vertex_attribute_object);

    glEnableVertexAttribArray(mater.position_location());
    glBindBuffer(GL_ARRAY_BUFFER, geom.vertex_buffer());
    glVertexAttribPointer(mater.position_location(), 3, GL_FLOAT, false, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geom.index_buffer());

    glBindVertexArray(0);
}

object::~object()
{
}

void object::render()
{
    //TODO: This does not work because of segfault. mater.use_program();
    glUniformMatrix4fv(mater.modelworld_matrix_location(),
            1, GL_FALSE, glm::value_ptr(world_matrix));
    glBindVertexArray(vertex_attribute_object);
    glDrawElements(GL_TRIANGLES, geom.element_count(), GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
    scene_node::render();
}
