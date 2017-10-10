#version 330 core

out vec4 FragColor;

void main() {
    FragColor = vec4(1.0,1.0,1.0,1.0);
    if(gl_FragCoord.y > 71.0 && gl_FragCoord.y < 81.0) discard;
    if(gl_FragCoord.y > 142.0 && gl_FragCoord.y < 152.0) discard;
    if(gl_FragCoord.y > 213.0 && gl_FragCoord.y < 223.0) discard;
    if(gl_FragCoord.y > 284.0 && gl_FragCoord.y < 294.0) discard;
    if(gl_FragCoord.y > 355.0 && gl_FragCoord.y < 365.0) discard;
    if(gl_FragCoord.y > 426.0 && gl_FragCoord.y < 436.0) discard;
    if(gl_FragCoord.y > 497.0 && gl_FragCoord.y < 507.0) discard;
    if(gl_FragCoord.y > 568.0 && gl_FragCoord.y < 578.0) discard;
    if(gl_FragCoord.y > 639.0 && gl_FragCoord.y < 649.0) discard;
    if(gl_FragCoord.y > 710.0 && gl_FragCoord.y < 720.0) discard;


    if(gl_FragCoord.x <= 357.0) {
      if(gl_FragCoord.y > 357.0)  FragColor = vec4(1.0,0.0,0.0,1.0);
      else FragColor = vec4(1.0,1.0,0.0,1.0);
    }
    else {
      if(gl_FragCoord.y > 357.0) FragColor = vec4(0.0,0.0,1.0,1.0);
      else FragColor = vec4(0.0,1.0,0.0,1.0);
    }

}
