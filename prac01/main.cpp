
// ======================================================
// @brief  Simple Shader Sample
// @author Lacty / y.akira
// @date   2017.02.19
// ======================================================

#include <iostream>
#include <GLFW/glfw3.h>


int main() {
  if (!glfwInit()) return -1;
  
  auto* window = glfwCreateWindow(256, 256, "Simple Shader Sample", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  
  glfwMakeContextCurrent(window);
  
  glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
  
  auto isOpen = [] (GLFWwindow* window)->bool {
    return !glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE);
  };
  
  while(isOpen(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  glfwTerminate();
}
