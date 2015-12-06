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
    material(gltools::program* program);
    virtual ~material();

    void use_program();

    GLuint position_location() const;
    GLuint normal_location() const;
    GLuint texture_coordinate_location() const;
    GLuint modelworld_matrix_location() const;
    GLuint view_matrix_location() const;
    GLuint projection_matrix_location() const;
private:
    gltools::program* program;

    //Attributes
    GLuint position;
    GLuint normal;
    GLuint texture_coordinate;

    //Uniforms
    GLuint modelworld;
    GLuint view;
    GLuint projection;

    //TODO: glm::vec4 diffuse_color;
    //TODO: glm::vec4 specular_color;
    //TODO: GLfloat shine;
};

#endif /* SRC_MATERIAL_H_ */
