/*
 * object.h
 *
 *  Created on: 6. des. 2015
 *      Author: larso
 */

#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

#include "scene.h"
#include "geometry.h"
#include "material.h"

class object : public scene_node
{
public:
    object(geometry& geom, material& mater);
    virtual ~object();

    void render();

private:
    geometry& geom;
    material& mater;

    GLuint vertex_attribute_object;
};

#endif /* SRC_OBJECT_H_ */
