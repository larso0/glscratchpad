/*
 * material.cpp
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#include "material.h"
#include <stdexcept>

namespace scene
{

material::material(shader_program* p) :
        _program(p)
{
    if(p == nullptr)
    {
        throw std::invalid_argument("Program can not be a nullpointer.");
    }
}

material::~material()
{
}

void material::setup_attributes()
{
}

void material::send_data()
{
}

shader_program* material::program()
{
    return _program;
}

} /* namespace scene */
