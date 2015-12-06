/*
 * geometry.cpp
 *
 *  Created on: 5. des. 2015
 *      Author: larso
 */

#include "geometry.h"
#include <stdexcept>

const size_t vertex::position_offset = 0;
const size_t vertex::normal_offset = sizeof(glm::vec3);
const size_t vertex::uv_offset = 2*sizeof(glm::vec3);
const size_t vertex::stride = sizeof(vertex);

geometry::geometry() :
        initialized(false), vbuffer(0)
{
}

geometry::~geometry()
{
    glDeleteBuffers(1, &vbuffer);
}

void geometry::initialize()
{
    if (!initialized)
    {
        glGenBuffers(1, &vbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex),
                vertices.data(), GL_STATIC_DRAW);
        initialized = true;
    }
}

void geometry::add_vertex(vertex v)
{
    vertices.push_back(v);
}

size_t geometry::vertex_count() const
{
    return vertices.size();
}

GLuint geometry::vertex_buffer() const
{
    if (!initialized)
    {
        throw std::runtime_error(
                "Must be initialized before retrieval of vertex buffer");
    }
    return vbuffer;
}
