
// ======================================================
// @brief  Simple Shader Sample
// @author Lacty / y.akira
// @date   2017.02.19
// ======================================================

#include <iostream>
#include <string>
#include <cassert>

#include <GLFW/glfw3.h>
#include <GL/glext.h>

int main() {
  // inisialize glfw
  if (!glfwInit()) return -1;
  
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  // --------------------------------------------------------------
  // util funcs
  // --------------------------------------------------------------
  auto makeWindow = [] (int w, int h)->GLFWwindow* {
    auto window = glfwCreateWindow(w, h, "", nullptr, nullptr);
    if (window) {
      glfwMakeContextCurrent(window);
      return window;
    }
    glfwTerminate();
    return nullptr;
  };

  auto isOpen = [] (GLFWwindow* window)->bool {
    return !glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE);
  };
  
  auto begin = [] ()->void {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  };
  
  auto end = [] (GLFWwindow* window)->void {
    glfwSwapBuffers(window);
    glfwPollEvents();
  };
  
  // ---------------------------------------------------------------
  // make window width:256 height:256
  // ---------------------------------------------------------------
  auto window = makeWindow(256, 256);
  if (!window) return -1;

  // ---------------------------------------------------------------
  // helper funcs
  // ---------------------------------------------------------------  
  auto glCreateShader         = (PFNGLCREATESHADERPROC)glfwGetProcAddress("glCreateShader");
  auto glShaderSource         = (PFNGLSHADERSOURCEPROC)glfwGetProcAddress("glShaderSource");
  auto glCompileShader        = (PFNGLCOMPILESHADERPROC)glfwGetProcAddress("glCompileShader");
  auto glCreateProgram        = (PFNGLCREATEPROGRAMPROC)glfwGetProcAddress("glCreateProgram");
  auto glAttachShader         = (PFNGLATTACHSHADERPROC)glfwGetProcAddress("glAttachShader");
  auto glDeleteShader         = (PFNGLDELETESHADERPROC)glfwGetProcAddress("glDeleteShader");
  auto glDeleteProgram        = (PFNGLDELETEPROGRAMPROC)glfwGetProcAddress("glDeleteProgram");
  auto glBindAttribLocation   = (PFNGLBINDATTRIBLOCATIONPROC)glfwGetProcAddress("glBindAttribLocation");
  auto glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)glfwGetProcAddress("glBindFragDataLocation");
  auto glLinkProgram          = (PFNGLLINKPROGRAMPROC)glfwGetProcAddress("glLinkProgram");
  auto glUseProgram           = (PFNGLUSEPROGRAMPROC)glfwGetProcAddress("glUseProgram");
  
  // vtx array(rect
  static const GLfloat vtx[] = {
    -0.5, -0.5,
    +0.5, -0.5,
    +0.5, +0.5,
    -0.5, +0.5
  };
  auto dispRect = [] (const GLfloat* vtx)->void {
    glVertexPointer(2, GL_FLOAT, 0, vtx);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
  };
  
  // vretex shader source code
  static const char* vtx_shader {
    "#version 150 core\n"
    "varying float x, y, z;\n"
    "void main(void)\n"
    "{\n"
      "gl_Position = ftransform();"
      "x = gl_Position.x; y = gl_Position.y; z = gl_Position.z;"
    "}\n"
  };
  
  // fragment shader source code
  static const char* frg_shader {
    "#version 150 core\n"
    "varying float x, y, z;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(1.0, 0.0, 1.0, 1.0);\n"
    "}\n"
  };

  // create shader obj
  auto vtx_s = glCreateShader(GL_VERTEX_SHADER);
  auto frg_s = glCreateShader(GL_FRAGMENT_SHADER);
  
  assert(vtx_s);
  assert(frg_s);
  
  // set shader source code
  glShaderSource(vtx_s, 1, &vtx_shader, 0);
  glShaderSource(frg_s, 1, &frg_shader, 0);
  
  // compile
  glCompileShader(vtx_s);
  glCompileShader(frg_s);
  
  // create program obj
  auto program = glCreateProgram();
  glAttachShader(program, vtx_s);
  glAttachShader(program, frg_s);
  
  // link to OpenGL
  glLinkProgram(program);

  // use program obj
  glUseProgram(program);
  
  while(isOpen(window)) {
    begin();
    
    dispRect(vtx);
    
    end(window);
  }
    
  glfwTerminate();
}
