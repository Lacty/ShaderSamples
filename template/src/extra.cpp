
// =====================================================================
// @file   extra.h
// @brief  エクストラ関数実装部
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

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
PFNGLGETUNIFORMLOCATIONPROC   glGetUniformLocation;
PFNGLUNIFORM1FPROC            glUniform1f;
PFNGLUNIFORM2FPROC            glUniform2f;
PFNGLUNIFORM3FPROC            glUniform3f;
PFNGLUNIFORM4FPROC            glUniform4f;
PFNGLUNIFORM1IPROC            glUniform1i;
PFNGLUNIFORM2IPROC            glUniform2i;
PFNGLUNIFORM3IPROC            glUniform3i;
PFNGLUNIFORM4IPROC            glUniform4i;
PFNGLUNIFORM1FVPROC           glUniform1fv;
PFNGLUNIFORM2FVPROC           glUniform2fv;
PFNGLUNIFORM3FVPROC           glUniform3fv;
PFNGLUNIFORM4FVPROC           glUniform4fv;
PFNGLUNIFORM1IVPROC           glUniform1iv;
PFNGLUNIFORM2IVPROC           glUniform2iv;
PFNGLUNIFORM3IVPROC           glUniform3iv;
PFNGLUNIFORM4IVPROC           glUniform4iv;

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
  glGetUniformLocation   = (PFNGLGETUNIFORMLOCATIONPROC)glfwGetProcAddress("glGetUniformLocation");
  glUniform1f            = (PFNGLUNIFORM1FPROC)glfwGetProcAddress("glUniform1f");
  glUniform2f            = (PFNGLUNIFORM2FPROC)glfwGetProcAddress("glUniform2f");
  glUniform3f            = (PFNGLUNIFORM3FPROC)glfwGetProcAddress("glUniform3f");
  glUniform4f            = (PFNGLUNIFORM4FPROC)glfwGetProcAddress("glUniform4f");
  glUniform1i            = (PFNGLUNIFORM1IPROC)glfwGetProcAddress("glUniform1i");
  glUniform2i            = (PFNGLUNIFORM2IPROC)glfwGetProcAddress("glUniform2i");
  glUniform3i            = (PFNGLUNIFORM3IPROC)glfwGetProcAddress("glUniform3i");
  glUniform4i            = (PFNGLUNIFORM4IPROC)glfwGetProcAddress("glUniform4i");
  glUniform1fv           = (PFNGLUNIFORM1FVPROC)glfwGetProcAddress("glUniform1fv");
  glUniform2fv           = (PFNGLUNIFORM2FVPROC)glfwGetProcAddress("glUniform2fv");
  glUniform3fv           = (PFNGLUNIFORM3FVPROC)glfwGetProcAddress("glUniform3fv");
  glUniform4fv           = (PFNGLUNIFORM4FVPROC)glfwGetProcAddress("glUniform4fv");
  glUniform1iv           = (PFNGLUNIFORM1IVPROC)glfwGetProcAddress("glUniform1iv");
  glUniform2iv           = (PFNGLUNIFORM2IVPROC)glfwGetProcAddress("glUniform2iv");
  glUniform3iv           = (PFNGLUNIFORM3IVPROC)glfwGetProcAddress("glUniform3iv");
  glUniform4iv           = (PFNGLUNIFORM4IVPROC)glfwGetProcAddress("glUniform4iv");
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