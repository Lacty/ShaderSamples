
// =====================================================================
// @file   shader.h
// @brief  シェーダー読み込んだりコンパイルしたりするクラス
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

#include <iostream>
#include <GLFW/glfw3.h>


class Shader {
public:
  Shader(const std::string& vtx_path, const std::string& frg_path);
  ~Shader();
  
  void on();
  void off();
  
private:
  
  GLuint m_vtxShaderId;
  GLuint m_frgShaderId;
  
  GLuint m_programId;
};