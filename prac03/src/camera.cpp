
// =====================================================================
// @file   camera.cpp
// @brief  メインカメラ
// @author Lacty / y.akira
// @data   2017.03.25
// =====================================================================

#include "camera.h"


Camera::Camera(const ymat::Vecf& pos,
                       const ymat::Vecf& target,
                       const float near,
                       const float far,
                       const float fovy,
                        const ymat::Veci& window) :
pos_(pos),
target_(target),
up_(ymat::Vecf(0, 1, 0)),
near_(near),
far_(far),
fovy_(fovy),
aspect_(window.x / (float)window.y) {}


void Camera::perspView() {
  float f = float(1. / std::tan(ymat::toRadians(fovy_) * 0.5));
  float g = -((far_ + near_) / (far_ - near_));
  float h = -((2 * far_ * near_) / (far_ - near_));
  float i = f / aspect_;

  ymat::TMatrix<float> m {
     i, 0.0f, 0.0f, 0.0f,
  0.0f,    f, 0.0f, 0.0f,
  0.0f, 0.0f,    g,    h,
  0.0f, 0.0f,   -1, 0.0f
   };

  glMultMatrixf(m.ptr());
}

void Camera::perspTrans() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  perspView();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Camera::lookToTarget() {
  ymat::Vecf z = getForward() / getForward().length();

  ymat::Vecf b = up_.cross(z);
  ymat::Vecf x = b / b.length();

  ymat::Vecf y = z.cross(x);

  ymat::Matf R {
    x.x,   x.y,  x.z, 0.0f,
    y.x,   y.y,  y.z, 0.0f,
    z.x,   z.y,  z.z, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  };

  ymat::Matf T {
    1.0f, 0.0f, 0.0f, -pos_.x,
    0.0f, 1.0f, 0.0f, -pos_.y,
    0.0f, 0.0f, 1.0f, -pos_.z,
    0.0f, 0.0f, 0.0f,    1.0f
  };

  ymat::Matf m = R * T;
  glMultMatrixf(m.ptr());
}

void Camera::update() {
  perspTrans();
  lookToTarget();
}

void Camera::windowSizeCallBack(const int width, const int height) {
  aspect_ = width / (float)height;
}


void Camera::setPos(const ymat::Vecf& pos) { pos_ = pos; }
void Camera::setTarget(const ymat::Vecf& target) { target_ = target; }
void Camera::setUp(const ymat::Vecf& up) { up_ = up; }

void Camera::setNear(const float near) { near_ = near; }
void Camera::setFar(const float far) { far_ = far; }
void Camera::setFovy(const float fovy) { fovy_ = fovy; }

const ymat::Vecf& Camera::getPos() const { return pos_; }
const ymat::Vecf& Camera::getTarget() const { return target_; }
const ymat::Vecf& Camera::getUp() const { return up_; }

const float& Camera::getNear() const { return near_; }
const float& Camera::getFar() const { return far_; }
const float& Camera::getFovy() const { return fovy_; }

ymat::Vecf Camera::getForward() const {
  return pos_ - target_;
}