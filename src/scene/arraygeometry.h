/*
 * arraygeometry.h
 *
 *  Created on: 9. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_ARRAYGEOMETRY_H_
#define SRC_SCENE_ARRAYGEOMETRY_H_

#include "geometry.h"
#include <vector>

namespace scene
{

class array_geometry : public geometry
{
public:
    array_geometry();
    virtual ~array_geometry();

    void send_data();
    void setup_attributes(GLint position_loc, GLint normal_loc, GLint uv_loc);
    void draw();

private:
    bool data_sent;
    bool vao_setup;
    GLuint vbuffer;
};

} /* namespace scene */

#endif /* SRC_SCENE_ARRAYGEOMETRY_H_ */
