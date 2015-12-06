/*
 * material.h
 *
 *  Created on: 6. des. 2015
 *      Author: larso
 */

#ifndef SRC_MATERIAL_H_
#define SRC_MATERIAL_H_

#include "gl_includes.h"
#include "program.h"

class material
{
public:
    material();
    virtual ~material();

private:
    glm::vec4 diffuse_color;
    glm::vec4 specular_color;
    GLfloat shine;
};

#endif /* SRC_MATERIAL_H_ */
