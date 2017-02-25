#version 130

// 現在処理されるピクセルの位置
in vec2 Vertex;

// fragシェーダーに渡されるデータ
out vec2 FragCoord;

void main(void)
{
  gl_Position = gl_ModelViewMatrix * vec4(Vertex, 0.0, 1.0);
  FragCoord = Vertex;
}