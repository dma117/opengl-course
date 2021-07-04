#pragma once

class EBO {
 public:
  EBO(unsigned int[], unsigned int);
  ~EBO();

  void Bind();
 private:
  unsigned int id;
};
