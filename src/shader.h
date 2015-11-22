/*
 * shader.h
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#ifndef SHADER_H_
#define SHADER_H_

#include "gl_includes.h"
#include <string>

namespace gltools
{

class shader
{
public:
    shader(std::string file_path, GLenum shader_type);
    ~shader();

    void compile();
    GLuint get_object_id() const;
    const std::string& get_source() const;
    const std::string& get_infolog() const;

private:
    GLenum shader_type;
    GLuint object_id;
    bool compiled;
    std::string source;
    std::string infolog;
};

} /* namespace gltools */

#endif /* SHADER_H_ */
