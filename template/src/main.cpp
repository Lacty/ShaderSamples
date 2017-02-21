
#include "app.h"


int main() {
  App app(360, 360);
  app.setBgColor({0.4, 0.4, 0.4, 1.0});
  
  Shader shader("data/v_shader.vsp", "data/f_shader.fsp");
  
  while(app.isOpen()) {
    app.begin();
    
    shader.on();
    drawRect(0, 0, 2);
    shader.off();
    
    glColor3f(1, 1, 1);
    drawPoint(0, 0, 5);
    
    app.end();
  }
}
