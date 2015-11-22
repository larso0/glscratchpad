/*
 * program.cpp
 *
 *  Created on: 21. nov. 2015
 *      Author: larso
 */

#include "program.h"
#include <stdexcept>

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

namespace gltools
{

program::program() :
        shaders_attached(false),
        object_id(0),
        linked(false)
{
}

program::~program()
{
    glDeleteProgram(object_id);
}

void program::attach_shader(const shader& shdr)
{
    if(!shaders_attached)
    {
        object_id = glCreateProgram();
        shaders_attached = true;
    }
    glAttachShader(object_id, shdr.get_object_id());
}

void program::link()
{
    if(!shaders_attached)
    {
        throw std::runtime_error("Shaders need to be attached before linking program.");
    }
    glLinkProgram(object_id);
    GLint link_status = 0;
    glGetProgramiv(object_id, GL_LINK_STATUS, &link_status);
    infolog = program_info_log(object_id);
    if (link_status == GL_FALSE)
    {
        throw std::runtime_error("Unable to link program: " + infolog);
    }

    linked = true;
}

GLuint program::get_object_id() const
{
    if(!shaders_attached)
    {
        throw std::runtime_error("Shaders need to be attached before retrieval of object id.");
    }
    return object_id;
}

const std::string& program::get_infolog() const
{
    return infolog;
}

void program::use()
{
    if(!(shaders_attached && linked))
    {
        throw std::runtime_error("Program must be linked before usage.");
    }
    glUseProgram(object_id);
}

GLint program::get_attribute_location(std::string attribute_name)
{
    GLint loc = glGetAttribLocation(object_id, attribute_name.c_str());
    if(loc == -1)
    {
        throw std::runtime_error("Could not get attribute location for attribute with name \"" + attribute_name + "\".");
    }
    return loc;
}

GLint program::get_uniform_location(std::string uniform_name)
{
    GLint loc = glGetUniformLocation(object_id, uniform_name.c_str());
    if(loc == -1)
    {
        throw std::runtime_error("Could not get uniform location for uniform with name \"" + uniform_name + "\".");
    }
    return loc;
}

} /* namespace gltools */
