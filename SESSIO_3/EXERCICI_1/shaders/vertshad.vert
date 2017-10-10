#version 330 core

in vec3 vertex;
in vec3 color;
out vec3 fragColor;
uniform float val;

void main()  {
    gl_Position = vec4 (vertex*val, 1.0);
    fragColor = color;
}
