
#include "app.h"


int main() {
  App app(360, 360);
  app.setBgColor({0.4, 0.4, 0.4, 1.0});
  
  while(app.isOpen()) {
    app.begin();
    
    app.end();
  }
}
