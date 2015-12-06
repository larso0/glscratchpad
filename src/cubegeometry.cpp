/*
 * cubegeometry.cpp
 *
 *  Created on: 6. des. 2015
 *      Author: larso
 */

#include "cubegeometry.h"

cube_geometry::cube_geometry()
{
    vertex(glm::vec3(-0.5f, -0.5f, 0.5f));
    vertex(glm::vec3(0.5f, -0.5f, 0.5f));
    vertex(glm::vec3(0.5f, 0.5f, 0.5f));
    vertex(glm::vec3(-0.5f, 0.5f, 0.5f));
    vertex(glm::vec3(-0.5f, -0.5f, -0.5f));
    vertex(glm::vec3(0.5f, -0.5f, -0.5f));
    vertex(glm::vec3(0.5f, 0.5f, -0.5f));
    vertex(glm::vec3(-0.5f, 0.5f, -0.5f));
    face(0, 1, 2);
    face(2, 3, 0);
    face(3, 2, 6);
    face(6, 7, 3);
    face(7, 6, 5);
    face(5, 4, 7);
    face(4, 0, 3);
    face(3, 7, 4);
    face(0, 5, 1);
    face(4, 5, 0);
    face(1, 5, 6);
    face(6, 2, 1);
}

