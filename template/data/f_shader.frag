#version 130

in vec2 pos;
out vec4 fragColor;

void main(void)
{
  fragColor = vec4(pos + vec2(0.5, 0.5), 0.5, 1.0);
}