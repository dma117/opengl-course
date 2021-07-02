#pragma once
#include <SFML/Window.hpp>
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera {
 public:
  Camera();
  glm::mat4 GetProjectionMatrix();
  glm::mat4 GetViewMatrix();

  glm::vec3 GetVecFront() const;
  glm::vec3 GetVecUp() const;
  glm::vec3 GetPosition() const;
  void SetVecFront(const glm::vec3&); 

  void Move(glm::vec3);
 private:
  glm::vec3 position_;
  glm::vec3 vec_up_;
  glm::vec3 vec_front_;

  float ratio_;
  float fov_;
  float near_;
  float far_;
};