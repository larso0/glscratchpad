/*
 * indexedgeometry.cpp
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#include "indexedgeometry.h"
#include <stdexcept>

namespace scene
{

indexed_geometry::indexed_geometry() :
        geometry(), data_sent(false), vao_setup(false),
        vbuffer(0), ibuffer(0)
{
}

indexed_geometry::~indexed_geometry()
{
    if(data_sent)
    {
        glDeleteBuffers(1, &vbuffer);
        glDeleteBuffers(1, &ibuffer);
    }
}

void indexed_geometry::send_data()
{
    if(!data_sent)
    {
        glGenBuffers(1, &vbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
        glBufferData(GL_ARRAY_BUFFER,
                vertices.size() * sizeof(geometry::vertex_),
                vertices.data(), GL_STATIC_DRAW);
        glGenBuffers(1, &ibuffer);
        glBindBuffer(GL_ARRAY_BUFFER, ibuffer);
        glBufferData(GL_ARRAY_BUFFER, indices.size() * sizeof(GLushort),
                        indices.data(), GL_STATIC_DRAW);
        data_sent = true;
    }
}

void indexed_geometry::setup_attributes(GLint position_loc, GLint normal_loc,
        GLint uv_loc)
{
    if(!data_sent)
    {
        throw std::runtime_error("Data must be sent to GPU with send_data() before setting up the attributes.");
    }
    if(!vao_setup)
    {
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
        glEnableVertexAttribArray(position_loc);
        glVertexAttribPointer(position_loc, 3, GL_FLOAT, false, vertex_::stride,
                (GLvoid*)vertex_::position_offset);
        glEnableVertexAttribArray(normal_loc);
        glVertexAttribPointer(normal_loc, 3, GL_FLOAT, false, vertex_::stride,
                (GLvoid*)vertex_::normal_offset);
        glEnableVertexAttribArray(uv_loc);
        glVertexAttribPointer(uv_loc, 2, GL_FLOAT, false, vertex_::stride,
                (GLvoid*)vertex_::uv_offset);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibuffer);
        glBindVertexArray(0);
        vao_setup = true;
    }
}

void indexed_geometry::draw()
{
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
}

void indexed_geometry::face(GLushort a, GLushort b, GLushort c)
{
    indices.push_back(a);
    indices.push_back(b);
    indices.push_back(c);
}

} /* namespace scene */
