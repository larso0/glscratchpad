#version 450

in vec3 position;

uniform mat4 modelview;
uniform mat4 projection;

out vec3 modelposition;

void main()
{
	modelposition = position;
	gl_Position = projection * modelview * vec4(position, 1);
}