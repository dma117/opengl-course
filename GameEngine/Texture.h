#pragma once

class Texture {
 public:
  static int count;

  Texture(const char*);
  
  unsigned int GetTextureId() const;

  void Bind();
 private:
  unsigned int id;
  int unit;
};