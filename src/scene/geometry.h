/*
 * geometry.h
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_GEOMETRY_H_
#define SRC_SCENE_GEOMETRY_H_

#include "scene_commons.h"
#include <vector>

namespace scene
{

class geometry
{
public:
    geometry();
    virtual ~geometry();

    void vertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 uv);
    virtual void send_data() = 0;
    virtual void setup_attributes(GLint position_loc, GLint normal_loc, GLint uv_loc) = 0;
    virtual void draw() = 0;

protected:
    class vertex_
    {
    public:
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
        static const size_t position_offset;
        static const size_t normal_offset;
        static const size_t uv_offset;
        static const size_t stride;
    };

    GLuint vao;
    std::vector<vertex_> vertices;
};

} /* namespace scene */

#endif /* SRC_SCENE_GEOMETRY_H_ */
