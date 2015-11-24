/*
 * mesh.cpp
 *
 *  Created on: 24. nov. 2015
 *      Author: larso
 */

#include "mesh.h"

namespace gltools
{

mesh::mesh(program& progr)
{
    initialize_data();

    glGenVertexArrays(1, &vertex_attribute_object);
    glBindVertexArray(vertex_attribute_object);

    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &index_buffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex),
            vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(progr.get_attribute_location("position"), 3, GL_FLOAT,
            vertex::STRIDE, vertex::POSITION_OFFSET);
    glVertexAttribPointer(progr.get_attribute_location("normal"), 3, GL_FLOAT,
            vertex::STRIDE, vertex::NORMAL_OFFSET);
    glVertexAttribPointer(progr.get_attribute_location("uv"), 2, GL_FLOAT,
            vertex::STRIDE, vertex::UV_OFFSET);
    glVertexAttribPointer(progr.get_attribute_location("color"), 3, GL_FLOAT,
            vertex::STRIDE, vertex::COLOR_OFFSET);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort),
            indices.data(), GL_STATIC_DRAW);
}

mesh::~mesh()
{
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteBuffers(1, &index_buffer);
    glDeleteVertexArrays(1, &vertex_attribute_object);
}

} /* namespace gltools */
