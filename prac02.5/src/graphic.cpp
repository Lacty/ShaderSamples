
#include "graphic.h"


auto drawRect(const GLfloat x, const GLfloat y, const GLfloat size)->void {
  GLfloat half = size * 0.5f;
  const GLfloat vtx[] = {
    x - half, y - half,
    x + half, y - half,
    x + half, y + half,
    x - half, y + half
  };
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_QUADS, 0, 4);
  glDisableClientState(GL_VERTEX_ARRAY);
};

auto drawPoint(const GLfloat x, const GLfloat y, const GLfloat size, const GLboolean smooth)->void {
  const GLfloat vtx[] = { x, y };
  if (smooth) {
    glEnable(GL_POINT_SMOOTH);
  }
  glPointSize(size);
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_POINTS, 0, 1);
  glDisableClientState(GL_VERTEX_ARRAY);
};