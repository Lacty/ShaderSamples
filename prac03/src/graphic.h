
#pragma once

#include <iostream>
#include <GLFW/glfw3.h>


// 矩形の描画
auto drawRect(const GLfloat x, const GLfloat y, const GLfloat size)->void;

// 点を描画
auto drawPoint(const GLfloat x, const GLfloat y, const GLfloat size, const GLboolean smooth = true)->void;
