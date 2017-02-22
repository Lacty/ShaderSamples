
#include "app.h"


int main() {
  App app(360, 360);
  app.setBgColor({0.4, 0.4, 0.4, 1.0});
  
  Shader shader("data/v_shader.vert", "data/f_shader.frag");
  
  while(app.isOpen()) {
    app.begin();
    
    shader.on();
    drawRect(0, 0, 2);
    shader.off();
        
    app.end();
  }
}
