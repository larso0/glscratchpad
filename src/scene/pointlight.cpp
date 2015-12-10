/*
 * pointlight.cpp
 *
 *  Created on: 10. des. 2015
 *      Author: larso
 */

#include "pointlight.h"

namespace scene
{

point_light::point_light(GLuint lposition_loc, GLuint lcolor_loc) :
        node(), color(1.f, 1.f, 1.f), lposition(lposition_loc), lcolor(lcolor_loc)
{
}

void point_light::send_data()
{
    glUniform3fv(lposition, 1, glm::value_ptr(pos));
    glUniform3fv(lcolor, 1, glm::value_ptr(color));
}

} /* namespace scene */
