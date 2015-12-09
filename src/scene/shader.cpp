/*
 * shader.cpp
 *
 *  Created on: 9. des. 2015
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

namespace scene
{

shader::shader(std::string file, GLenum shader_type) :
        shader_type(shader_type),
        id(0),
        compiled(false)
{
    src = file_to_string(file);
}

shader::~shader()
{
    if(compiled)
    {
        glDeleteShader(id);
    }
}

void shader::compile()
{
    id = glCreateShader(shader_type);
    const GLchar* csrc = src.c_str();
    glShaderSource(id, 1, &csrc, nullptr);

    glCompileShader(id);
    GLint compile_status = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compile_status);
    log = shader_info_log(id);
    if (compile_status == GL_FALSE)
    {
        glDeleteShader(id);
        throw std::runtime_error("Unable to compile shader: " + log);
    }

    compiled = true;
}

GLuint shader::object_id() const
{
    if(!compiled)
    {
        throw std::runtime_error("Shader must be compiled before retrieval of object id.");
    }
    return id;
}

const std::string& shader::source() const
{
    return src;
}

const std::string& shader::infolog() const
{
    return log;
}

} /* namespace scene */
