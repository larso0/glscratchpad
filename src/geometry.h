/*
 * geometry.h
 *
 *  Created on: 5. des. 2015
 *      Author: larso
 */

#ifndef SRC_GEOMETRY_H_
#define SRC_GEOMETRY_H_

#include "gl_includes.h"
#include <vector>
#include <cinttypes>

class vertex
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

class geometry
{
public:
    geometry();
    virtual ~geometry();

    void initialize();

    void add_vertex(vertex v);

    size_t vertex_count() const;
    GLuint vertex_buffer() const;
protected:
    std::vector<vertex> vertices;

private:
    bool initialized;
    GLuint vbuffer;
};

#endif /* SRC_GEOMETRY_H_ */
