
#include "extra.h"


void extra_gl_func::InitEx() {
  glCreateShader         = (PFNGLCREATESHADERPROC)glfwGetProcAddress("glCreateShader");
  glShaderSource         = (PFNGLSHADERSOURCEPROC)glfwGetProcAddress("glShaderSource");
  glCompileShader        = (PFNGLCOMPILESHADERPROC)glfwGetProcAddress("glCompileShader");
  glCreateProgram        = (PFNGLCREATEPROGRAMPROC)glfwGetProcAddress("glCreateProgram");
  glAttachShader         = (PFNGLATTACHSHADERPROC)glfwGetProcAddress("glAttachShader");
  glDeleteShader         = (PFNGLDELETESHADERPROC)glfwGetProcAddress("glDeleteShader");
  glDeleteProgram        = (PFNGLDELETEPROGRAMPROC)glfwGetProcAddress("glDeleteProgram");
  glBindAttribLocation   = (PFNGLBINDATTRIBLOCATIONPROC)glfwGetProcAddress("glBindAttribLocation");
  glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)glfwGetProcAddress("glBindFragDataLocation");
  glLinkProgram          = (PFNGLLINKPROGRAMPROC)glfwGetProcAddress("glLinkProgram");
  glUseProgram           = (PFNGLUSEPROGRAMPROC)glfwGetProcAddress("glUseProgram");
  glGetShaderiv          = (PFNGLGETSHADERIVPROC)glfwGetProcAddress("glGetShaderiv");
  glGetShaderInfoLog     = (PFNGLGETSHADERINFOLOGPROC)glfwGetProcAddress("glGetShaderInfoLog");
  glGetProgramiv         = (PFNGLGETPROGRAMIVPROC)glfwGetProcAddress("glGetProgramiv");
  glGetProgramInfoLog    = (PFNGLGETPROGRAMINFOLOGPROC)glfwGetProcAddress("glGetProgramInfoLog");
}