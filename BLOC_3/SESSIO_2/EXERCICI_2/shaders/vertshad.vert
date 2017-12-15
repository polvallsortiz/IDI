#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

out vec3 matamb2;
out vec3 matdiff2;
out vec3 matspec2;
out float matshin2;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

uniform vec4 posFocusSCO;

out vec3 normalSCO;
out vec4 vertexSCO;


// Valors per als components que necessitem dels focus de llum
//vec3 colFocus = vec3(0.8, 0.8, 0.8);
//vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
//vec3 posFocus = vec3(1, 0, 0);  // en SCA


void main()
{
    //vec4 posFocusSCO = vec4(posFocus,1.0)*view;
    mat3 NormalMatrix = inverse(transpose(mat3(view*TG)));
    vec4 vertexSCO = (view * TG * vec4(vertex,1.0));
    //vec3 L = normalize(posFocusSCO.xyz - vertexSCO.xyz);
    vec3 normalSCO = normalize(NormalMatrix * normal);
    //fcolor = Phong(normalSCO,L,vertexSCO);
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
    //PAS A FRAGMENT SHADER
    matamb2 = matamb;
    matdiff2 = matdiff;
    matspec2 = matspec;
    matshin2 = matshin;

}
