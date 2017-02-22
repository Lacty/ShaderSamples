
#include "app.h"


int main() {
  App app(360, 360);
  app.setBgColor({0.4, 0.4, 0.4, 1.0});
  
  //glOrtho(-app.width() * 0.5,app.width() * 0.5,-app.height() * 0.5, app.height() * 0.5,0.0f, 1.0f);
  
  Shader shader("data/v_shader.vert", "data/f_shader.frag");
  shader.on();
  
  while(app.isOpen()) {
    app.begin();
    
    const GLfloat mouse[] = {
      GLfloat(app.mouseX()) - app.width() * 0.5f,
      (GLfloat(app.mouseY()) - app.height() * 0.5f) * -1
    };
    const GLfloat window[] = {
      GLfloat(app.width()),
      GLfloat(app.height())
    };
    
    shader.uniform2f("mouse", mouse);
    shader.uniform2f("window", window);
    
    drawRect(0, 0, 1.9);
    
    app.end();
  }
}
