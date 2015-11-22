/*
 * shader.cpp
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#include "shader.h"
#include <fstream>
#include <stdexcept>

std::string file_to_string(std::string fileName)
{
    std::ifstream file(fileName);
    if(!file.is_open())
    {
        throw std::runtime_error("Could not open file '" + fileName + "'.");
    }

    std::string str;

    file.seekg(0, std::ios::end);
    str.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());
    return str;
}

std::string shader_info_log(GLuint shader)
{
    GLint len = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    GLchar* cstr = new GLchar[len];
    glGetShaderInfoLog(shader, len, &len, cstr);
    std::string log(cstr);
    delete[] cstr;
    return log;
}

namespace gltools
{

shader::shader(std::string file, GLenum shader_type) :
        shader_type(shader_type),
        object_id(0),
        compiled(false)
{
    source = file_to_string(file);
}

shader::~shader()
{
    if(compiled)
    {
        glDeleteShader(object_id);
    }
}

void shader::compile()
{
    object_id = glCreateShader(shader_type);
    const GLchar* src = source.c_str();
    glShaderSource(object_id, 1, &src, nullptr);

    glCompileShader(object_id);
    GLint compile_status = 0;
    glGetShaderiv(object_id, GL_COMPILE_STATUS, &compile_status);
    infolog = shader_info_log(object_id);
    if (compile_status == GL_FALSE)
    {
        glDeleteShader(object_id);
        throw std::runtime_error("Unable to compile shader: " + infolog);
    }

    compiled = true;
}

GLuint shader::get_object_id() const
{
    if(!compiled)
    {
        throw std::runtime_error("Shader must be compiled before retrieval of object id.");
    }
    return object_id;
}

const std::string& shader::get_source() const
{
    return source;
}

const std::string& shader::get_infolog() const
{
    return infolog;
}

} /* namespace gltools */
