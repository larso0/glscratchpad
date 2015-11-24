/*
 * mesh.h
 *
 *  Created on: 24. nov. 2015
 *      Author: larso
 */

#ifndef SRC_MESH_H_
#define SRC_MESH_H_

#include "gl_includes.h"
#include <vector>
#include "vertex.h"

namespace gltools
{

class mesh
{
public:
    mesh(program& progr);
    virtual ~mesh();

    virtual void initialize_data() = 0;
protected:
    std::vector<vertex> vertices;
    std::vector<GLushort> indices;

private:
    GLuint vertex_attribute_object;
    GLuint vertex_buffer;
    GLuint index_buffer;
};

} /* namespace gltools */

#endif /* SRC_MESH_H_ */
