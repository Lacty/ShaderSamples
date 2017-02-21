
// =====================================================================
// @file   extra.h
// @brief  デフォで用意されていない関数群
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

#include <GLFW/glfw3.h>


namespace extra_gl_func {
  // ===================================================================
  // funcs
  // ===================================================================
  static PFNGLCREATESHADERPROC         glCreateShader;
  static PFNGLSHADERSOURCEPROC         glShaderSource;
  static PFNGLCOMPILESHADERPROC        glCompileShader;
  static PFNGLCREATEPROGRAMPROC        glCreateProgram;
  static PFNGLATTACHSHADERPROC         glAttachShader;
  static PFNGLDELETESHADERPROC         glDeleteShader;
  static PFNGLDELETEPROGRAMPROC        glDeleteProgram;
  static PFNGLBINDATTRIBLOCATIONPROC   glBindAttribLocation;
  static PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
  static PFNGLLINKPROGRAMPROC          glLinkProgram;
  static PFNGLUSEPROGRAMPROC           glUseProgram;
  static PFNGLGETSHADERIVPROC          glGetShaderiv;
  static PFNGLGETSHADERINFOLOGPROC     glGetShaderInfoLog;
  static PFNGLGETPROGRAMIVPROC         glGetProgramiv;
  static PFNGLGETPROGRAMINFOLOGPROC    glGetProgramInfoLog;
  
  // it for initialize extra func
  void InitEx();
}