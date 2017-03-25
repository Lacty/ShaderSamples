
// =====================================================================
// @file   shader.h
// @brief  シェーダー読み込んだりコンパイルしたりするクラス
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

#pragma once

#include <iostream>
#include <GLFW/glfw3.h>


class Shader {
public:
  Shader() = default;
  Shader(const std::string& vtx_path, const std::string& frg_path);
  ~Shader();
  
  void on();
  void off();
  
  void uniform1f(const std::string& name, const GLfloat* data);
  void uniform2f(const std::string& name, const GLfloat* data);
  void uniform3f(const std::string& name, const GLfloat* data);
  void uniform4f(const std::string& name, const GLfloat* data);
  void uniform1i(const std::string& name, const GLint*   data);
  void uniform2i(const std::string& name, const GLint*   data);
  void uniform3i(const std::string& name, const GLint*   data);
  void uniform4i(const std::string& name, const GLint*   data);

private:
  
  GLuint m_vtxShaderId;
  GLuint m_frgShaderId;
  
  GLuint m_programId;
};