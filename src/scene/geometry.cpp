/*
 * geometry.cpp
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#include "geometry.h"

const size_t scene::geometry::vertex_::position_offset = 0;
const size_t scene::geometry::vertex_::normal_offset = sizeof(glm::vec3);
const size_t scene::geometry::vertex_::uv_offset = 2 * sizeof(glm::vec3);
const size_t scene::geometry::vertex_::stride = sizeof(geometry::vertex_);

namespace scene
{

geometry::geometry() : vao(0)
{
    glGenVertexArrays(1, &vao);
}

geometry::~geometry()
{
    glDeleteVertexArrays(1, &vao);
}

void geometry::vertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv)
{
    vertices.push_back( { pos, normal, uv });
}

} /* namespace scene */
