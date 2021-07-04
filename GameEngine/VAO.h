#pragma once
#include <GL/glew.h>

class VAO {
 public:
  VAO();
  ~VAO();

  void Bind();

  void EnableArray(GLuint, GLint, GLenum,
                   GLboolean, GLsizei,
                   const GLvoid*) const;
 private:
  unsigned int id;
};