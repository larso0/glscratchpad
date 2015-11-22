/*
 * program.h
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "gl_includes.h"
#include "shader.h"
#include <string>

namespace gltools
{

class program
{
public:
    program();
    ~program();

    void attach_shader(const shader& shdr);
    void link();
    GLuint get_object_id() const;
    const std::string& get_infolog() const;
    void use();
    GLint get_attribute_location(std::string attribute_name);
    GLint get_uniform_location(std::string uniform_name);

private:
    bool shaders_attached;
    GLuint object_id;
    bool linked;
    std::string infolog;
};

} /* namespace gltools */

#endif /* PROGRAM_H_ */
