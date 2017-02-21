
#include "app.h"


int main() {
  App app(360, 360);
  app.setBgColor({0.4, 0.4, 0.4, 1.0});
  
  // vtx array(rect
  static const GLfloat vtx[] = {
    -0.5, -0.5,
    +0.5, -0.5,
    +0.5, +0.5,
    -0.5, +0.5
  };
               
  auto drawRect = [] (const GLfloat* vtx)->void {
    glVertexPointer(2, GL_FLOAT, 0, vtx);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
  };
  
  Shader shader("v_shader.vsp", "f_shader.fsp");
  shader.on();
  
  while(app.isOpen()) {
    app.begin();
    
    drawRect(vtx);
    
    app.end();
  }
}
