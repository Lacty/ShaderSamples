
#include <iostream>
#include <GLFW/glfw3.h>
#include "extra.h"


class Shader {
public:
  Shader(const std::string& vtx_path, const std::string& frg_path);
  ~Shader();
  
  void on();
  void off();
  
private:
  
  GLuint m_vtxShaderId;
  GLuint m_frgShaderId;
  
  GLuint m_programId;
};