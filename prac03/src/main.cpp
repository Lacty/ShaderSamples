
#include "app.h"


int main() {
  App app(360, 360);
  app.setBgColor({0.4, 0.4, 0.4, 1.0});
  
  Shader shader("data/v_shader.vert", "data/f_shader.frag");
  shader.on();
  
  while(app.isOpen()) {
    app.begin();
    
    GLfloat mouse[] = {
      GLfloat(app.mouseX()),
      GLfloat(app.mouseY())
    };
    
    mouse[0] /= (app.width() * 0.5f);
    mouse[1] /= (app.height() * 0.5f);
    
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
