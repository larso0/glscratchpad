/*
 * vertex.h
 *
 *  Created on: 24. nov. 2015
 *      Author: larso
 */

#ifndef SRC_VERTEX_H_
#define SRC_VERTEX_H_

#include "gl_includes.h"

namespace gltools
{

class vertex
{
public:
    vertex()
    {
    }

    vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv, glm::vec4 color) :
        position(position), normal(normal), uv(uv), color(color)
    {
    }
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
    glm::vec4 color;

    static const GLsizei STRIDE = sizeof(vertex);
    static const GLvoid* POSITION_OFFSET = 0;
    static const GLvoid* NORMAL_OFFSET = sizeof(glm::vec3);
    static const GLvoid* UV_OFFSET = 2*sizeof(glm::vec3);
    static const GLvoid* COLOR_OFFSET = 2*sizeof(glm::vec3) + sizeof(glm::vec2);
};

} /* namespace gltools */

#endif /* SRC_VERTEX_H_ */
