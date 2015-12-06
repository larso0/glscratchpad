/*
 * cubegeometry.cpp
 *
 *  Created on: 6. des. 2015
 *      Author: larso
 */

#include "cubegeometry.h"

using glm::vec3;
using glm::vec2;

cube_geometry::cube_geometry()
{
    add_vertex({vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(0.f, 0.f)});
    add_vertex({vec3(0.5f, -0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(1.f, 0.f)});
    add_vertex({vec3(0.5f, 0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(1.f, 1.f)});
    add_vertex({vec3(0.5f, 0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(1.f, 1.f)});
    add_vertex({vec3(-0.5f, 0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(0.f, 1.f)});
    add_vertex({vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, 0.f, 1.f), vec2(0.f, 0.f)});
    add_vertex({vec3(-0.5f, 0.5f, 0.5f), vec3(0.f, 1.f, 0.f), vec2(0.f, 0.f)});
    add_vertex({vec3(0.5f, 0.5f, 0.5f), vec3(0.f, 1.f, 0.f), vec2(1.f, 0.f)});
    add_vertex({vec3(0.5f, 0.5f, -0.5f), vec3(0.f, 1.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(0.5f, 0.5f, -0.5f), vec3(0.f, 1.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(-0.5f, 0.5f, -0.5f), vec3(0.f, 1.f, 0.f), vec2(0.f, 1.f)});
    add_vertex({vec3(-0.5f, 0.5f, 0.5f), vec3(0.f, 1.f, 0.f), vec2(0.f, 0.f)});
    add_vertex({vec3(-0.5f, 0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(0.f, 0.f)});
    add_vertex({vec3(0.5f, 0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(1.f, 0.f)});
    add_vertex({vec3(0.5f, -0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(1.f, 1.f)});
    add_vertex({vec3(0.5f, -0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(1.f, 1.f)});
    add_vertex({vec3(-0.5f, -0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(0.f, 1.f)});
    add_vertex({vec3(-0.5f, 0.5f, -0.5f), vec3(0.f, 0.f, -1.f), vec2(0.f, 0.f)});
    add_vertex({vec3(-0.5f, -0.5f, -0.5f), vec3(-1.f, 0.f, 0.f), vec2(0.f, 0.f)});
    add_vertex({vec3(-0.5f, -0.5f, 0.5f), vec3(-1.f, 0.f, 0.f), vec2(1.f, 0.f)});
    add_vertex({vec3(-0.5f, 0.5f, 0.5f), vec3(-1.f, 0.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(-0.5f, 0.5f, 0.5f), vec3(-1.f, 0.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(-0.5f, 0.5f, -0.5f), vec3(-1.f, 0.f, 0.f), vec2(0.f, 1.f)});
    add_vertex({vec3(-0.5f, -0.5f, -0.5f), vec3(-1.f, 0.f, 0.f), vec2(0.f, 0.f)});
    add_vertex({vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, -1.f, 0.f), vec2(0.f, 0.f)});
    add_vertex({vec3(0.5f, -0.5f, -0.5f), vec3(0.f, -1.f, 0.f), vec2(1.f, 0.f)});
    add_vertex({vec3(0.5f, -0.5f, 0.5f), vec3(0.f, -1.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(-0.5f, -0.5f, -0.5f), vec3(0.f, -1.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(0.5f, -0.5f, -0.5f), vec3(0.f, -1.f, 0.f), vec2(0.f, 1.f)});
    add_vertex({vec3(-0.5f, -0.5f, 0.5f), vec3(0.f, -1.f, 0.f), vec2(0.f, 0.f)});
    add_vertex({vec3(0.5f, -0.5f, 0.5f), vec3(1.f, 0.f, 0.f), vec2(0.f, 0.f)});
    add_vertex({vec3(0.5f, -0.5f, -0.5f), vec3(1.f, 0.f, 0.f), vec2(1.f, 0.f)});
    add_vertex({vec3(0.5f, 0.5f, -0.5f), vec3(1.f, 0.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(0.5f, 0.5f, -0.5f), vec3(1.f, 0.f, 0.f), vec2(1.f, 1.f)});
    add_vertex({vec3(0.5f, 0.5f, 0.5f), vec3(1.f, 0.f, 0.f), vec2(0.f, 1.f)});
    add_vertex({vec3(0.5f, -0.5f, 0.5f), vec3(1.f, 0.f, 0.f), vec2(0.f, 0.f)});
}

