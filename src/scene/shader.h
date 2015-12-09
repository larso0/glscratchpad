/*
 * shader.h
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_SHADER_H_
#define SRC_SCENE_SHADER_H_

#include "scene_commons.h"
#include <string>

namespace scene
{

class shader
{
public:
    shader(std::string file_path, GLenum shader_type);
    ~shader();

    void compile();
    GLuint object_id() const;
    const std::string& source() const;
    const std::string& infolog() const;

private:
    GLenum shader_type;
    GLuint id;
    bool compiled;
    std::string src;
    std::string log;
};

} /* namespace scene */

#endif /* SRC_SCENE_SHADER_H_ */
