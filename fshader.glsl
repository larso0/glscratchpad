#version 450

in vec3 modelposition;
out vec4 color;

void main()
{
	color = vec4((sin(modelposition.x)+1)/2,
				 (sin(modelposition.y)+1)/2,
				 (sin(modelposition.z)+1)/2, 1.0);
}