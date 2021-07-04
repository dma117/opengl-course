#pragma once

class VBO {
 public:
  VBO(float[], float);
  ~VBO();

  void Bind();
 private:
  unsigned int id;
};
