/*
 * object.h
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_OBJECT_H_
#define SRC_SCENE_OBJECT_H_

#include "scene_commons.h"
#include "node.h"
#include "geometry.h"
#include "material.h"

namespace scene
{

class object : public node
{
public:
    object(geometry* geom, material* mat);
    virtual ~object();

    void render();
private:
    geometry* geom;
    material* mat;
    GLuint world_matrix_loc;
    GLuint view_matrix_loc;
};

} /* namespace scene */

#endif /* SRC_SCENE_OBJECT_H_ */
