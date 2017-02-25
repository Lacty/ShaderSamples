#version 130

in vec2 FragCoord;
out vec4 FragColor;

uniform vec2 mouse;
uniform vec2 window;

void main(void)
{
  vec2 pos = mouse;
  
  vec4 color = vec4(0.0);
  
  float dist = length(FragCoord - pos);
  
  float size = 5.0;
  color += (size / dist);
  
  FragColor = color;
}
