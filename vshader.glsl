#version 450

in vec3 position;

uniform vec3 rotation_axis;
uniform float rotation_angle;
uniform mat4 modelview;
uniform mat4 projection;

out vec3 modelposition;

mat3 rotate(vec3 axis, float angle)
{
    axis = normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;
    
    return mat3(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,
                oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,
                oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c);
}

void main()
{
	modelposition = position;
	gl_Position = projection * modelview *
				  vec4(rotate(rotation_axis, rotation_angle) * position, 1);
}