#include "VBO.h"
#include <GL/glew.h>

VBO::VBO(float vertices[], float size) {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ARRAY_BUFFER, id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * size, vertices, GL_STATIC_DRAW);
}

VBO::~VBO() {
  glDeleteBuffers(1, &id);
}

void VBO::Bind() {
  glBindBuffer(GL_ARRAY_BUFFER, id);
}
