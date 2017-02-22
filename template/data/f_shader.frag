#version 130

varying float x, y, z;

void main(void)
{
  gl_FragColor = vec4(x, y, z, 1.0);
}