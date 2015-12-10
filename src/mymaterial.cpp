/*
 * mymaterial.cpp
 *
 *  Created on: 10. des. 2015
 *      Author: larso
 */

#include "mymaterial.h"

mymaterial::mymaterial(scene::shader_program* p) :
        scene::material(p)
{
}

void mymaterial::send_data()
{
    glUniform3fv(diffuse_loc, 1, glm::value_ptr(diffuse));
}
