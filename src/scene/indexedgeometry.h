/*
 * indexedgeometry.h
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_INDEXEDGEOMETRY_H_
#define SRC_SCENE_INDEXEDGEOMETRY_H_

#include "geometry.h"

namespace scene
{

class indexed_geometry : public geometry
{
public:
    indexed_geometry();
    virtual ~indexed_geometry();

    void send_data();
    void setup_attributes(GLint position_loc, GLint normal_loc, GLint uv_loc);
    void draw();

    void face(GLushort a, GLushort b, GLushort c);
private:
    std::vector<GLushort> indices;
    bool data_sent;
    bool vao_setup;
    GLuint vbuffer;
    GLuint ibuffer;
};

} /* namespace scene */

#endif /* SRC_SCENE_INDEXEDGEOMETRY_H_ */
