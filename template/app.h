
// =====================================================================
// @file   app.h
// @brief  アプリクラス
// @author Lacty / y.akira
// @data   2017.02.21
// =====================================================================

#include <iostream>
#include <GLFW/glfw3.h>

#include "extra.h"


class App {
public:
  struct color_t {
    float r, g, b, a;
    color_t(float r, float g, float b, float a)
      : r(r), g(g), b(b), a(a) {}
  };
  
  App(int w, int h);
  ~App();

  // is window open?
  bool isOpen();
  
  // plz call befor draw
  void begin();
  
  // plz call after draw
  void end();

  // return window size
  int width() const;
  int height() const;
  
  void setBgColor(color_t color);
  
private:
  GLFWwindow* p_window;
  
  int m_width;
  int m_height;
  
  color_t m_bgColor;
};