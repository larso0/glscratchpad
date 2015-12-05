/*
 * scene.h
 *
 *  Created on: 5. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_H_
#define SRC_SCENE_H_

#include "gl_includes.h"
#include <vector>

class scene_node
{
public:
    scene_node(scene_node* parent = nullptr);
    virtual ~scene_node();

    void set_parent(scene_node* parent);
    void add(scene_node* child);

    void rotate_euler(glm::vec3 angles);
    void rotate(glm::vec3 axis, float angle);
    void translate(glm::vec3 t);
    void scale(glm::vec3 s);

    virtual void render();
private:
    scene_node* parent;
    std::vector<scene_node*> children;

    glm::quat rotation_quaternion;
    glm::vec3 translation;
    glm::vec3 scale_vector;

    glm::mat4 world_matrix;

    bool needs_update;
    void update_matrices();
};

typedef scene_node scene;

#endif /* SRC_SCENE_H_ */
