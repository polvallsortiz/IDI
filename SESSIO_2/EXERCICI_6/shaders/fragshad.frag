#version 330 core

in vec3 colorf;
out vec4 FragColor;


void main() {
    FragColor = vec4(colorf,1);
}
