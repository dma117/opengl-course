#pragma once
#include <SFML/Window.hpp>
#include "math.h"

class Camera {
 public:
  Camera();
  Mat4 GetProjectionMatrix() const;
  Mat4 GetViewMatrix() const;

  Vec3 GetVecFront() const;
  Vec3 GetVecUp() const;
  Vec3 GetPosition() const;
  void SetVecFront(const Vec3&); 

  void Translate(const Vec3&);
 private:
  Vec3 position_;
  Vec3 vec_up_;
  Vec3 vec_front_;

  float ratio_;
  float fov_;
  float near_;
  float far_;
};