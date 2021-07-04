#include "VAO.h"

VAO::VAO() {
  glGenVertexArrays(1, &id);
  glBindVertexArray(id);
}

VAO::~VAO() {
  glDeleteVertexArrays(1, &id);
}

void VAO::Bind() {
  glBindVertexArray(id);
}

void VAO::EnableArray(GLuint index, GLint size, GLenum type,
                      GLboolean normalized, GLsizei stride,
                      const GLvoid* pointer) const {
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
  glEnableVertexAttribArray(index);
}
