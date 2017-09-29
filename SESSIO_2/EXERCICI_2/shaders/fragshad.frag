#version 330 core

out vec4 FragColor;
in vec3 fragColor;

void main() {
    FragColor = vec4(fragColor,1.0);
    if(gl_FragCoord.x > 0.0) FragColor = vec4(1.0,1.0,1.0,1.0);
}

