
#include <iostream>
#include "extra.h"

namespace extra_gl_func {
PFNGLCREATESHADERPROC         glCreateShader;
PFNGLSHADERSOURCEPROC         glShaderSource;
PFNGLCOMPILESHADERPROC        glCompileShader;
PFNGLCREATEPROGRAMPROC        glCreateProgram;
PFNGLATTACHSHADERPROC         glAttachShader;
PFNGLDELETESHADERPROC         glDeleteShader;
PFNGLDELETEPROGRAMPROC        glDeleteProgram;
PFNGLBINDATTRIBLOCATIONPROC   glBindAttribLocation;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
PFNGLLINKPROGRAMPROC          glLinkProgram;
PFNGLUSEPROGRAMPROC           glUseProgram;
PFNGLGETSHADERIVPROC          glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC     glGetShaderInfoLog;
PFNGLGETPROGRAMIVPROC         glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC    glGetProgramInfoLog;

void InitEx() {
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


auto printShaderInfoLog(GLuint shader, const char *str)->GLboolean
{
  // コンパイル結果を取得する
  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if (status == GL_FALSE) std::cerr << "Compile Error in " << str << std::endl;
  
  // シェーダのコンパイル時のログの長さを取得する
  GLsizei bufSize;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH , &bufSize);
  
  if (bufSize > 1)
  {
    // シェーダのコンパイル時のログの内容を取得する
    GLchar *infoLog = new GLchar[bufSize];
    GLsizei length;
    glGetShaderInfoLog(shader, bufSize, &length, infoLog);
    std::cerr << infoLog << std::endl;
    delete[] infoLog;
  }
  
  return (GLboolean)status;
};


auto printProgramInfoLog(GLuint program)->GLboolean
{
  // リンク結果を取得する
  GLint status;
  glGetProgramiv(program, GL_LINK_STATUS, &status);
  if (status == GL_FALSE) std::cerr << "Link Error" << std::endl;
  
  // シェーダのリンク時のログの長さを取得する
  GLsizei bufSize;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH , &bufSize);
  
  if (bufSize > 1)
  {
    // シェーダのリンク時のログの内容を取得する
    GLchar *infoLog = new GLchar[bufSize];
    GLsizei length;
    glGetProgramInfoLog(program, bufSize, &length, infoLog);
    std::cerr << infoLog << std::endl;
    delete[] infoLog;
  }
  
  return (GLboolean)status;
};

}