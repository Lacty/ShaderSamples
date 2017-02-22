#version 130

in vec2 fragCoord;
out vec4 fragColor;

uniform vec2 mouse;
uniform vec2 window;

void main(void)
{
  vec2 pos = vec2(0.0);
  
  vec4 color = vec4(0.0);
  
  float dist = length(fragCoord - pos);
  
  float size = 0.06;
  color += (size / dist);
  
  fragColor = color;
}
