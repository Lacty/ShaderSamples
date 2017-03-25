
// =====================================================================
// @file   camera.h
// @brief  メインカメラ
// @author Lacty / y.akira
// @data   2017.03.25
// =====================================================================

#pragma once

#include <GLFW/glfw3.h>
#include "ymat/ymat.h"


class Camera {
public:
  Camera() = delete;
  Camera(const ymat::Vecf& pos,
         const ymat::Vecf& target,
         const float near,
         const float far,
         const float fovy,
         const ymat::Veci& window);
  
  void update();
  void windowSizeCallBack(const int width, const int height);
  
  void setPos(const ymat::Vecf& pos);
  void setTarget(const ymat::Vecf& target);
  void setUp(const ymat::Vecf& up);
  
  void setNear(const float near);
  void setFar(const float far);
  void setFovy(const float fovy);
  
  const ymat::Vecf& getPos() const;
  const ymat::Vecf& getTarget() const;
  const ymat::Vecf& getUp() const;
  
  const float& getNear() const;
  const float& getFar() const;
  const float& getFovy() const;
  
  ymat::Vecf getForward() const;

private:
  ymat::Vecf pos_;
  ymat::Vecf target_;
  ymat::Vecf up_;
  
  float near_;
  float far_;
  float fovy_;
  float aspect_;
  
  void perspView();
  void perspTrans();
  void lookToTarget();
};