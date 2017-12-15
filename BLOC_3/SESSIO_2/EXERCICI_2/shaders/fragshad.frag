#version 330 core

out vec4 FragColor;

in vec3 matamb2;
in vec3 matdiff2;
in vec3 matspec2;
in float matshin2;

in vec4 vertexSCO;
in vec3 normalSCO;

uniform vec3 colFocus;
uniform vec3 llumAmbient;
uniform vec4 posFocusSCO;

vec3 Lambert (vec3 NormSCO, vec3 L)
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb2;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiff2 * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO)
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshin2 == 0))
      return colRes;  // no hi ha component especular

    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshin2);
    return (colRes + matspec2 * colFocus * shine);
}

void main()
{
    vec3 L = normalize(posFocusSCO.xyz - vertexSCO.xyz);
    vec3 fcolor = Phong(normalize(normalSCO),L,vertexSCO);
	FragColor = vec4(fcolor,1);
}
