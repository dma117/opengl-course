#include "EBO.h"
#include <GL/glew.h>

EBO::EBO(unsigned int indices[], unsigned int size) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * size, indices, GL_STATIC_DRAW);
}

void EBO::Bind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
