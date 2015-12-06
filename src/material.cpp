/*
 * material.cpp
 *
 *  Created on: 6. des. 2015
 *      Author: larso
 */

#include "material.h"

material::material(gltools::program& program) :
    program(program)
{
    position = program.get_attribute_location("position");
    normal = 0;//program.get_attribute_location("normal");
    texture_coordinate = 0;//program.get_attribute_location("uv");
    modelworld = program.get_uniform_location("modelworld");
    view = program.get_uniform_location("view");
    projection = program.get_uniform_location("projection");
}

material::~material()
{
}

void material::use_program()
{
    program.use();
}

GLuint material::position_location() const
{
    return position;
}

GLuint material::normal_location() const
{
    return normal;
}

GLuint material::texture_coordinate_location() const
{
    return texture_coordinate;
}

GLuint material::modelworld_matrix_location() const
{
    return modelworld;
}

GLuint material::view_matrix_location() const
{
    return view;
}

GLuint material::projection_matrix_location() const
{
    return projection;
}
