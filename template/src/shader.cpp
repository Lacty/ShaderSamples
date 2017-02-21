
// =====================================================================
// @file   shader.h
// @brief  シェーダークラス実装部
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

#include <fstream>
#include <cassert>
#include "shader.h"
#include "extra.h"


Shader::Shader(const std::string& vtx_path, const std::string& frg_path) {
  using namespace extra_gl_func;
  
  std::ifstream vtx_s(vtx_path);
  std::ifstream frg_s(frg_path);
  
  // assert if cannot load file
  assert(!vtx_s.fail());
  assert(!frg_s.fail());
  
  std::string vtx_str((std::istreambuf_iterator<char>(vtx_s)),
                    std::istreambuf_iterator<char>());
  std::string frg_str((std::istreambuf_iterator<char>(frg_s)),
                    std::istreambuf_iterator<char>());
  
  // create shader
  m_vtxShaderId = glCreateShader(GL_VERTEX_SHADER);
  m_frgShaderId = glCreateShader(GL_FRAGMENT_SHADER);
  
  assert(m_vtxShaderId);
  assert(m_frgShaderId);
  
  // set shader source code
  const char* v_str = vtx_str.c_str();
  const char* f_str = frg_str.c_str();
  glShaderSource(m_vtxShaderId, 1, &v_str, 0);
  glShaderSource(m_frgShaderId, 1, &f_str, 0);
  
  // compile shader
  glCompileShader(m_vtxShaderId);
  glCompileShader(m_frgShaderId);
  
  // output err log
  printShaderInfoLog(m_vtxShaderId, "vertex shader");
  printShaderInfoLog(m_frgShaderId, "fragment shader");
  
  // create program obj
  m_programId = glCreateProgram();
  glAttachShader(m_programId, m_vtxShaderId);
  glAttachShader(m_programId, m_frgShaderId);
  
  // link to OpenGL
  glLinkProgram(m_programId);
  
  // output err log
  printProgramInfoLog(m_programId);
}

Shader::~Shader() {
  using namespace extra_gl_func;
  
  // delete shader
  glDeleteShader(m_vtxShaderId);
  glDeleteShader(m_frgShaderId);
  
  // reset shader program
  glUseProgram(0);
}

void Shader::on() {
  using namespace extra_gl_func;  
  glUseProgram(m_programId);
}

void Shader::off() {
  using namespace extra_gl_func;
  glUseProgram(0);
}