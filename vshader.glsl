#version 450

in vec3 position;

uniform vec3 rotation_axis;
uniform float rotation_angle;
uniform mat4 modelview;
uniform mat4 projection;

out vec3 modelposition;

vec3 qtransform( vec4 q, vec3 v )
{ 
	return v + 2.0*cross(cross(v, q.xyz ) + q.w*v, q.xyz);
}

vec3 rotate(vec3 vec, vec3 axis, float angle)
{
	axis = normalize(axis);
	vec4 quat = vec4(sin(angle/2)*axis, cos(angle/2));
	return qtransform(quat, vec);
}

void main()
{
	modelposition = position;
	gl_Position = projection * modelview *
				  vec4(rotate(position, rotation_axis, rotation_angle), 1);
}