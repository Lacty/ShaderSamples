
// =====================================================================
// @file   extra.h
// @brief  デフォで用意されていない関数群
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

#pragma once

#include <GLFW/glfw3.h>


namespace extra_gl_func {
  // ===================================================================
  // funcs
  // ===================================================================
  extern PFNGLCREATESHADERPROC         glCreateShader;
  extern PFNGLSHADERSOURCEPROC         glShaderSource;
  extern PFNGLCOMPILESHADERPROC        glCompileShader;
  extern PFNGLCREATEPROGRAMPROC        glCreateProgram;
  extern PFNGLATTACHSHADERPROC         glAttachShader;
  extern PFNGLDELETESHADERPROC         glDeleteShader;
  extern PFNGLDELETEPROGRAMPROC        glDeleteProgram;
  extern PFNGLBINDATTRIBLOCATIONPROC   glBindAttribLocation;
  extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
  extern PFNGLLINKPROGRAMPROC          glLinkProgram;
  extern PFNGLUSEPROGRAMPROC           glUseProgram;
  extern PFNGLGETSHADERIVPROC          glGetShaderiv;
  extern PFNGLGETSHADERINFOLOGPROC     glGetShaderInfoLog;
  extern PFNGLGETPROGRAMIVPROC         glGetProgramiv;
  extern PFNGLGETPROGRAMINFOLOGPROC    glGetProgramInfoLog;
  extern PFNGLGETUNIFORMLOCATIONPROC   glGetUniformLocation;
  extern PFNGLUNIFORM1FPROC            glUniform1f;
  extern PFNGLUNIFORM2FPROC            glUniform2f;
  extern PFNGLUNIFORM3FPROC            glUniform3f;
  extern PFNGLUNIFORM4FPROC            glUniform4f;
  extern PFNGLUNIFORM1IPROC            glUniform1i;
  extern PFNGLUNIFORM2IPROC            glUniform2i;
  extern PFNGLUNIFORM3IPROC            glUniform3i;
  extern PFNGLUNIFORM4IPROC            glUniform4i;
  extern PFNGLUNIFORM1FVPROC           glUniform1fv;
  extern PFNGLUNIFORM2FVPROC           glUniform2fv;
  extern PFNGLUNIFORM3FVPROC           glUniform3fv;
  extern PFNGLUNIFORM4FVPROC           glUniform4fv;
  extern PFNGLUNIFORM1IVPROC           glUniform1iv;
  extern PFNGLUNIFORM2IVPROC           glUniform2iv;
  extern PFNGLUNIFORM3IVPROC           glUniform3iv;
  extern PFNGLUNIFORM4IVPROC           glUniform4iv;
  
  // it for initialize extra func
  void InitEx();
  
  // シェーダオブジェクトのコンパイル結果を表示する
  auto printShaderInfoLog(GLuint shader, const char *str)->GLboolean;
  
  // プログラムオブジェクトのリンク結果を表示する
  auto printProgramInfoLog(GLuint program)->GLboolean;
}