#version 130

// 現在処理されるピクセルの位置
in vec2 position;

// fragシェーダーに渡されるデータ
out vec2 pos;

void main(void)
{
  gl_Position = vec4(position, 0.0, 1.0);
  pos = position;
}