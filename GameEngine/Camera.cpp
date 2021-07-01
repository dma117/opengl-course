#include "Camera.h"

Camera::Camera() : 
	position_(glm::vec3(0, 0, 3)), 
	vec_up_(glm::vec3(0, 1, 0)), 
	vec_front_(glm::vec3(0, 0, -1)), 
	ratio_(1920.f / 1080),
	fov_(glm::radians(70.f)), 
	near_(0.1f), 
	far_(100.f) {}

glm::mat4 Camera::GetProjectionMatrix() {
  return glm::perspective(fov_, ratio_, near_, far_);
}

glm::mat4 Camera::GetViewMatrix() {
  return glm::lookAt(position_, position_ + vec_front_, vec_up_);
}

glm::vec3 Camera::GetVecFront() const { return vec_front_; }

glm::vec3 Camera::GetVecUp() const {
  return vec_up_; }

glm::vec3 Camera::GetPosition() const {
  return position_;
}

void Camera::SetVecFront(const glm::vec3& new_vec_front) {
  vec_front_ = new_vec_front;
}

void Camera::Move(glm::vec3 offset) {
  position_ += offset;
}
