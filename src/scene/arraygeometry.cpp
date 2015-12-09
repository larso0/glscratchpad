/*
 * arraygeometry.cpp
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#include "arraygeometry.h"
#include <stdexcept>

namespace scene
{

array_geometry::array_geometry() :
        geometry(), data_sent(false), vao_setup(false), vbuffer(0)
{
}

array_geometry::~array_geometry()
{
    if (data_sent)
    {
        glDeleteBuffers(1, &vbuffer);
    }
}

void array_geometry::send_data()
{
    if (!data_sent)
    {
        glGenBuffers(1, &vbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
        glBufferData(GL_ARRAY_BUFFER,
                vertices.size() * sizeof(geometry::vertex_),
                vertices.data(), GL_STATIC_DRAW);
        data_sent = true;
    }
}

void array_geometry::setup_attributes(GLint position_loc, GLint normal_loc,
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
        glBindVertexArray(0);
        vao_setup = true;
    }
}

void array_geometry::draw()
{
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    glBindVertexArray(0);
}

} /* namespace scene */
