#pragma once

class Texture {
 public:
  Texture(const char*);

  unsigned int GetTextureId() const;

  void Bind();

 private:
  unsigned int id;
};