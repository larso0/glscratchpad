#version 450

in vec3 fposition;
in vec3 fnormal;
out vec4 color;

void main()
{
	vec3 ambientl = vec3(0.1, 0.1, 0.1);
	vec3 diffusem = vec3(0.7, 0.7, 0.7);
	vec3 lightpos = vec3(0.0, -2.5, 5.7);
	vec3 lightdir = normalize(fposition - lightpos);
	float brightness = dot(lightdir, normalize(fnormal)); 
	if(brightness < 0) brightness = 0;
	color = vec4(ambientl*diffusem + diffusem*brightness, 1.0);
}