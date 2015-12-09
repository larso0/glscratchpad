/*
 * shader_program.h
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#ifndef SHADER_PROGRAM_H_
#define SHADER_PROGRAM_H_

#include "scene_commons.h"
#include "shader.h"
#include <string>

namespace scene
{

class shader_program
{
public:
    shader_program();
    ~shader_program();

    void attach_shader(const shader& shdr);
    void link();
    GLuint object_id() const;
    const std::string& infolog() const;
    void use();
    GLint attribute_location(std::string attribute_name);
    GLint uniform_location(std::string uniform_name);

private:
    bool shaders_attached;
    GLuint id;
    bool linked;
    std::string log;
};

} /* namespace scene */

#endif /* SHADER_PROGRAM_H_ */
