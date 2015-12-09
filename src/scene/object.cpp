/*
 * object.cpp
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#include "object.h"
#include <stdexcept>

namespace scene
{

object::object(geometry* geom, material* mat) :
        node(nullptr),
        geom(geom),
        mat(mat),
        world_matrix_loc(0),
        view_matrix_loc(0)
{
    if(geom == nullptr)
    {
        throw std::invalid_argument("Geometry can not be a nullpointer.");
    }
    if(mat == nullptr)
    {
        throw std::invalid_argument("Material can not be a nullpointer");
    }
    mat->program()->use();

    geom->send_data();
    geom->setup_attributes(0, 1, 2);

    world_matrix_loc = mat->program()->uniform_location("world_matrix");
    view_matrix_loc = mat->program()->uniform_location("view_matrix");
}

object::~object()
{
}

void object::render()
{
    mat->program()->use();
    glUniformMatrix4fv(world_matrix_loc, 1, GL_FALSE, glm::value_ptr(world_matrix));
    geom->draw();
    node::render();
}

} /* namespace scene */
