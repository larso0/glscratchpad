/*
 * mymaterial.h
 *
 *  Created on: 10. des. 2015
 *      Author: larso
 */

#ifndef SRC_MYMATERIAL_H_
#define SRC_MYMATERIAL_H_

#include "scene/material.h"

class mymaterial : public scene::material
{
public:
    mymaterial(scene::shader_program* p);
    void send_data();
    glm::vec3 diffuse;
private:
    GLuint diffuse_loc = 6;
};

#endif /* SRC_MYMATERIAL_H_ */
