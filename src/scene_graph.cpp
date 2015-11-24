/*
 * scene_graph.cpp
 *
 *  Created on: 23. nov. 2015
 *      Author: larso
 */

#include "scene_graph.h"

namespace gltools
{

scene_node::scene_node(scene_node* parent) :
        parent(parent)
{
}

scene_node::~scene_node()
{
}

void scene_node::set_parent(scene_node* parent)
{
    this->parent = parent;
}

void scene_node::add(scene_node* node)
{
    children.push_back(node);
}

} /* namespace gltools */
