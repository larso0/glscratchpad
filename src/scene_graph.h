/*
 * scene_graph.h
 *
 *  Created on: 23. nov. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_GRAPH_H_
#define SRC_SCENE_GRAPH_H_

#include "gl_includes.h"
#include <vector>

namespace gltools
{

class scene_node
{
public:
    scene_node(scene_node* parent = nullptr);
    ~scene_node();

    void set_parent(scene_node* parent);
    void add(scene_node* node);

private:
    scene_node* parent;
    std::vector<scene_node*> children;
    glm::mat4 transformation_matrix;
};

} /* namespace gltools */

#endif /* SRC_SCENE_GRAPH_H_ */
