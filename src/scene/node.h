/*
 * node.h
 *
 *  Created on: 8. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_NODE_H_
#define SRC_SCENE_NODE_H_

#include "scene_commons.h"
#include <vector>

namespace scene
{

class node
{
public:
    node(node* parent);
    virtual ~node();

    void set_parent(node* parent);
    void add(node* child);

    void rotate_euler(glm::vec3 angles);
    void rotate(glm::vec3 axis, float angle);
    void translate(glm::vec3 t);
    void scale(glm::vec3 s);

    virtual void render();

    const glm::vec3& position() const;
protected:
    node* parent;
    std::vector<node*> children;
    glm::mat4 world_matrix;
    glm::vec3 pos;

private:
    glm::quat rotation_quaternion;
    glm::vec3 translation;
    glm::vec3 scale_vector;
    bool default_scale;
    bool needs_update;

    void update();
};

} /* namespace scene */

#endif /* SRC_SCENE_NODE_H_ */
