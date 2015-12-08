/*
 * node.cpp
 *
 *  Created on: 8. des. 2015
 *      Author: larso
 */

#include "node.h"
#include <algorithm>
#include <stdexcept>

namespace scene
{

node::node(node* parent) :
        parent(parent), scale_vector(glm::vec3(1.f, 1.f, 1.f)), default_scale(
                true), needs_update(false)
{
    if (parent != nullptr)
    {
        parent->children.push_back(this);
    }
}

node::~node()
{
}

void node::set_parent(node* parent)
{
    if (this->parent != nullptr)
    {
        this->parent->children.erase(
                std::remove(this->parent->children.begin(),
                        this->parent->children.end(), this),
                this->parent->children.end());
    }
    this->parent = parent;
    if (parent != nullptr)
    {
        parent->children.push_back(this);
    }
}

void node::add(node* child)
{
    if (child == nullptr)
    {
        throw std::invalid_argument("Tried to add nullptr.");
    }
    children.push_back(child);
    child->set_parent(this);
}

void node::rotate_euler(glm::vec3 angles)
{
    rotate(glm::vec3(1.f, 0.f, 0.f), angles.x);
    rotate(glm::vec3(0.f, 1.f, 0.f), angles.y);
    rotate(glm::vec3(0.f, 0.f, 1.f), angles.z);
}

void node::rotate(glm::vec3 axis, float angle)
{
    rotation_quaternion *= glm::angleAxis(angle, glm::normalize(axis));
    needs_update = true;
}

void node::translate(glm::vec3 t)
{
    translation += t;
    needs_update = true;
}

void node::scale(glm::vec3 s)
{
    scale_vector = default_scale ? s : scale_vector + s;
    default_scale = false;
    needs_update = true;
}

void node::render()
{
    if (needs_update)
    {
        update();
    }
    for (node* child : children)
    {
        child->render();
    }
}

const glm::vec3& node::position() const
{
    return pos;
}

void node::update()
{
    glm::mat4 local_matrix = glm::translate(glm::mat4(), translation)
            * glm::mat4_cast(rotation_quaternion);

    if(parent != nullptr)
    {
        pos = parent->pos + translation;
        world_matrix = parent->world_matrix * local_matrix;
    }
    else
    {
        pos = translation;
        world_matrix = local_matrix;
    }

    for (node* child : children)
    {
        child->update();
    }
    world_matrix = glm::scale(world_matrix, scale_vector);
    needs_update = false;
}

} /* namespace scene */
