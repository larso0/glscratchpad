#version 450

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

layout(location = 0) uniform mat4 modelworld;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

out vec3 fposition;
out vec3 fnormal;

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
	mat4 mvp = projection * view * modelworld;
	mat3 normalmatrix = mat3(mvp);
	normalmatrix = inverse(normalmatrix);
	normalmatrix = transpose(normalmatrix);
	fnormal = normalize(normalmatrix * normal);
	vec4 pos = mvp * vec4(position, 1);
	fposition = pos.xyz;
	gl_Position = pos;
}