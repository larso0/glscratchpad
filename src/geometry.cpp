/*
 * geometry.cpp
 *
 *  Created on: 5. des. 2015
 *      Author: larso
 */

#include "geometry.h"
#include <stdexcept>

geometry::geometry() :
    initialized(false), ibuffer(0), vbuffer(0)
{
}

geometry::~geometry()
{
    glDeleteBuffers(1, &vbuffer);
    glDeleteBuffers(1, &ibuffer);
}

void geometry::initialize()
{
    glGenBuffers(1, &vbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, ibuffer);
    glBufferData(GL_ARRAY_BUFFER, indices.size()*sizeof(GLushort), indices.data(), GL_STATIC_DRAW);
}

void geometry::vertex(glm::vec3 v)
{
    vertices.push_back(v);
}

void geometry::face(GLushort a, GLushort b, GLushort c)
{
    indices.push_back(a);
    indices.push_back(b);
    indices.push_back(c);
}

size_t geometry::element_count() const
{
    return indices.size();
}

GLuint geometry::vertex_buffer() const
{
    if(!initialized)
    {
        throw std::runtime_error("Must be initialized before retrieval of vertex buffer");
    }
    return vbuffer;
}

GLuint geometry::index_buffer() const
{
    if(!initialized)
    {
        throw std::runtime_error("Must be initialized before retrieval of index buffer");
    }
    return ibuffer;
}
