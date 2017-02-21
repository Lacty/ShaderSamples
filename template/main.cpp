
#include "app.h"


int main() {
  App app(360, 360);
  app.setBgColor({0.4, 0.4, 0.4, 1.0});
  
  Shader shader("v_shader.vsp", "f_shader.fsp");
  
  while(app.isOpen()) {
    app.begin();
    
    app.end();
  }
}
