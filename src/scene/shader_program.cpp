/*
 * shader_program.cpp
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#include <stdexcept>
#include "shader_program.h"

std::string program_info_log(GLuint shader)
{
    GLint len = 0;
    glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &len);
    GLchar* cstr = new GLchar[len];
    glGetProgramInfoLog(shader, len, &len, cstr);
    std::string log(cstr);
    delete[] cstr;
    return log;
}

namespace scene
{

shader_program::shader_program() :
        shaders_attached(false),
        id(0),
        linked(false)
{
}

shader_program::~shader_program()
{
    glDeleteProgram(id);
}

void shader_program::attach_shader(const shader& shdr)
{
    if(!shaders_attached)
    {
        id = glCreateProgram();
        shaders_attached = true;
    }
    glAttachShader(id, shdr.object_id());
}

void shader_program::link()
{
    if(!shaders_attached)
    {
        throw std::runtime_error("Shaders need to be attached before linking program.");
    }
    glLinkProgram(id);
    GLint link_status = 0;
    glGetProgramiv(id, GL_LINK_STATUS, &link_status);
    log = program_info_log(id);
    if (link_status == GL_FALSE)
    {
        throw std::runtime_error("Unable to link program: " + log);
    }

    linked = true;
}

GLuint shader_program::object_id() const
{
    if(!shaders_attached)
    {
        throw std::runtime_error("Shaders need to be attached before retrieval of object id.");
    }
    return id;
}

const std::string& shader_program::infolog() const
{
    return log;
}

void shader_program::use()
{
    if(!(shaders_attached && linked))
    {
        throw std::runtime_error("Program must be linked before usage.");
    }
    glUseProgram(id);
}

GLint shader_program::attribute_location(std::string attribute_name)
{
    GLint loc = glGetAttribLocation(id, attribute_name.c_str());
    if(loc == -1)
    {
        throw std::runtime_error("Could not get attribute location for attribute with name \"" + attribute_name + "\".");
    }
    return loc;
}

GLint shader_program::uniform_location(std::string uniform_name)
{
    GLint loc = glGetUniformLocation(id, uniform_name.c_str());
    if(loc == -1)
    {
        throw std::runtime_error("Could not get uniform location for uniform with name \"" + uniform_name + "\".");
    }
    return loc;
}

} /* namespace scene */
