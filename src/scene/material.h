/*
 * material.h
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_MATERIAL_H_
#define SRC_SCENE_MATERIAL_H_

#include "scene_commons.h"
#include "shader_program.h"

namespace scene
{

class material
{
public:
    material(shader_program* p);
    virtual ~material();

    virtual void setup_attributes();
    virtual void send_data();

    shader_program* program();
protected:
    shader_program* _program;
};

} /* namespace scene */

#endif /* SRC_SCENE_MATERIAL_H_ */
