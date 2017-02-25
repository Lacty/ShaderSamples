
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
, m_mouseX( 0 )
, m_mouseY( 0 )
, m_bgColor(1, 1, 1, 1)
{
  // Initialize
  // -----------------------------------------------------------------
  if (!glfwInit()) {
    std::cout << "glfwInit() : fail\n";
    exit(EXIT_FAILURE);
  }
  
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
  
  extra_gl_func::InitEx();
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
  
  glfwGetCursorPos(p_window, &m_mouseX, &m_mouseY);
  glfwGetWindowSize(p_window, &m_width, &m_height);
  
  m_mouseX = m_mouseX - m_width * 0.5;
  m_mouseY = (m_mouseY - m_height * 0.5) * -1;
}

void App::end() {
  glfwSwapBuffers(p_window);
  glfwPollEvents();
}

int App::width()  const { return m_width; }
int App::height() const { return m_height; }

double App::mouseX() const { return m_mouseX; }
double App::mouseY() const { return m_mouseY; }

void App::setBgColor(color_t color) {
  m_bgColor = color;
}