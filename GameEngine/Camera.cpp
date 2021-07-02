#include "Camera.h"
#include "glm/trigonometric.hpp"

Camera::Camera() : 
	position_(Vec3(0, 0, 3)), 
	vec_up_(Vec3(0, 1, 0)), 
	vec_front_(Vec3(0, 0, -1)), 
	ratio_(1920.f / 1080),
	fov_(glm::radians(70.f)), 
	near_(0.1f), 
	far_(100.f) {}

Mat4 Camera::GetProjectionMatrix() {
  return Mat4::Perspective(fov_, ratio_, near_, far_);
}

Mat4 Camera::GetViewMatrix() {
  return Mat4::LookAt(position_, position_ + vec_front_, vec_up_);
}

Vec3 Camera::GetVecFront() const { return vec_front_; }

Vec3 Camera::GetVecUp() const {
  return vec_up_; }

Vec3 Camera::GetPosition() const {
  return position_;
}

void Camera::SetVecFront(const Vec3& new_vec_front) {
  vec_front_ = new_vec_front;
}

void Camera::Move(Vec3 offset) {
  position_ += offset;
}
