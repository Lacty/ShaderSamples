
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
  
  // it for initialize extra func
  void InitEx();
  
  // シェーダオブジェクトのコンパイル結果を表示する
  auto printShaderInfoLog(GLuint shader, const char *str)->GLboolean;
  
  // プログラムオブジェクトのリンク結果を表示する
  auto printProgramInfoLog(GLuint program)->GLboolean;
}