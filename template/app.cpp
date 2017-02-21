
// =====================================================================
// @file   app.cpp
// @brief  アプリクラス実装部
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

#include "app.h"


App::App(int w, int h)
: m_width ( w )
, m_height( h )
, m_bgColor(1, 1, 1, 1)
{
  // Initialize
  // -----------------------------------------------------------------
  if (!glfwInit()) {
    std::cout << "glfwInit() : fail\n";
    exit(EXIT_FAILURE);
  }
  extra_gl_func::InitEx();
  
  // Make Window
  // -----------------------------------------------------------------
  p_window = glfwCreateWindow(width(), height(), "", nullptr, nullptr);
  if (p_window) {
    glfwMakeContextCurrent(p_window);
  } else {
    std::cout << "glfwCreateWindow() : fail\n";
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
}
 
App::~App() {
  glfwTerminate();
}

bool App::isOpen() {
  return !glfwWindowShouldClose(p_window) && !glfwGetKey(p_window, GLFW_KEY_ESCAPE);
}

void App::begin() {
  glClearColor(m_bgColor.r, m_bgColor.g, m_bgColor.b, m_bgColor.a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void App::end() {
  glfwSwapBuffers(p_window);
  glfwPollEvents();
}

int App::width()  const { return m_width; }
int App::height() const { return m_height; }

void App::setBgColor(color_t color) {
  m_bgColor = color;
}