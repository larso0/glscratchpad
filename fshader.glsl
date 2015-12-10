#version 450

in vec3 fposition;
in vec3 fnormal;
in vec2 fuv;
in vec3 flposition;
out vec4 color;

layout(location = 4) uniform vec3 lambient;
layout(location = 5) uniform vec3 lcolor;
layout(location = 6) uniform vec3 mdiffuse;

void main()
{
	vec3 lightdir = normalize(fposition - flposition);
	float brightness = dot(lightdir, normalize(fnormal)); 
	if(brightness < 0) brightness = 0;
	color = vec4(lambient*mdiffuse + lcolor*mdiffuse*brightness, 1.0);
}