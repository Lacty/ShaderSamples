#version 130

// 現在処理されるピクセルの位置
in vec2 Vertex;

// fragシェーダーに渡されるデータ
out vec2 FragCoord;

void main(void)
{
  gl_Position = vec4(Vertex, 0.0, 1.0);
  FragCoord = Vertex;
  
  //gl_Position = ftransform();
  //fragCoord = vec2(gl_Position.x, gl_Position.y);
}