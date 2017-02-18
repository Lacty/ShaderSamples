
// ======================================================
// @brief  Simple Shader Sample
// @author Lacty / y.akira
// @date   2017.02.19
// ======================================================

#include <iostream>
#include <GLFW/glfw3.h>


int main() {
  // inisialize glfw
  if (!glfwInit()) return -1;
  
  // --------------------------------------------------------------
  // Util Funcs
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
  //
  // ---------------------------------------------------------------
  
  // make window with param
  auto window = makeWindow(256, 256);
  if (!window) return -1;
  
  while(isOpen(window)) {
    begin();
    
    end(window);
  }
    
  glfwTerminate();
}
