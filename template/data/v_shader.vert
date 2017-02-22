#version 130

varying float x, y, z;

void main(void)
{
  gl_Position = ftransform();
  x = gl_Position.x;
  y = gl_Position.y;
  z = gl_Position.z;
}