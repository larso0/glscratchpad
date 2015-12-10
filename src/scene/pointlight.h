/*
 * pointlight.h
 *
 *  Created on: 10. des. 2015
 *      Author: larso
 */

#ifndef SRC_SCENE_POINTLIGHT_H_
#define SRC_SCENE_POINTLIGHT_H_

#include "node.h"

namespace scene
{

class point_light : public node
{
public:
    point_light(GLuint lposition_loc, GLuint lcolor_loc);
    void send_data();
    glm::vec3 color;

private:
    GLuint lposition;
    GLuint lcolor;
};

} /* namespace scene */

#endif /* SRC_SCENE_POINTLIGHT_H_ */
