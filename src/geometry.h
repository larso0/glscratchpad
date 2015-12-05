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

class geometry
{
public:
    geometry();
    virtual ~geometry();

    void initialize();

    void vertex(glm::vec3 v);
    void face(GLushort a, GLushort b, GLushort c);

    size_t element_count() const;
    GLuint vertex_buffer() const;
    GLuint index_buffer() const;
protected:
    std::vector<glm::vec3> vertices;
    //TODO: std::vector<glm::vec3> normals;
    //TODO: std::vector<glm::vec2> texture_coordinates;
    std::vector<GLushort> indices;

private:
    bool initialized;
    GLuint vbuffer;
    GLuint ibuffer;
};

#endif /* SRC_GEOMETRY_H_ */
