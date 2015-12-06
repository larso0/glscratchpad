#version 450

in vec3 position;
in vec3 normal;
in vec2 uv;

uniform mat4 modelworld;
uniform mat4 view;
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
	gl_Position = projection * view * modelworld *
				  vec4(position, 1);
}