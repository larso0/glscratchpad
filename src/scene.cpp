/*
 * scene.cpp
 *
 *  Created on: 5. des. 2015
 *      Author: larso
 */

#include "scene.h"
#include <algorithm>
#include <stdexcept>

scene_node::scene_node(scene_node* parent) :
        parent(parent),
        scale_vector(glm::vec3(1.f, 1.f, 1.f)),
        needs_update(false)
{
    if (parent != nullptr)
    {
        parent->children.push_back(this);
    }
}

scene_node::~scene_node()
{
    for (scene_node* child : children)
    {
        delete child;
    }
}

void scene_node::set_parent(scene_node* parent)
{
    if (this->parent != nullptr)
    {
        this->parent->children.erase(
                std::remove(this->parent->children.begin(),
                        this->parent->children.end(), this),
                this->parent->children.end());
    }
    this->parent = parent;
    if(parent != nullptr)
    {
        parent->children.push_back(this);
    }
}

void scene_node::add(scene_node* child)
{
    if(child == nullptr)
    {
        throw std::invalid_argument("Tried to add nullptr.");
    }
    children.push_back(child);
    child->set_parent(this);
}

void scene_node::rotate_euler(glm::vec3 angles)
{
    rotate(glm::vec3(1.f, 0.f, 0.f), angles.x);
    rotate(glm::vec3(0.f, 1.f, 0.f), angles.y);
    rotate(glm::vec3(0.f, 0.f, 1.f), angles.z);
}

void scene_node::rotate(glm::vec3 axis, float angle)
{
    rotation_quaternion *= glm::angleAxis(angle, glm::normalize(axis));
    needs_update = true;
}

void scene_node::translate(glm::vec3 t)
{
    translation += t;
    needs_update = true;
}

void scene_node::scale(glm::vec3 s)
{
    scale_vector += s;
    needs_update = true;
}

void scene_node::update_matrices()
{
    glm::mat4 local_matrix = glm::translate(glm::mat4(), translation) *
                   glm::mat4_cast(rotation_quaternion);

    if(parent != nullptr)
    {
        world_matrix = parent->world_matrix * local_matrix;
    }
    else
    {
        world_matrix = local_matrix;
    }
    for(scene_node* child : children)
    {
        child->update_matrices();
    }
    world_matrix = glm::scale(world_matrix, scale_vector);
    needs_update = false;
}

void scene_node::render()
{
    if(needs_update)
    {
        update_matrices();
    }
    for(scene_node* child : children)
    {
        child->render();
    }
}
