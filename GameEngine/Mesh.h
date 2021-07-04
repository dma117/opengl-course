#pragma once

#include <string>
#include <vector>
#include "Shader.h"

struct Vertex {
  Vec3 Position;
  Vec3 Normal;
  Vec2 TexCoords;
  Vec3 Tangent;
  Vec3 Bitangent;
};

struct MeshTexture {
  unsigned int id;
  std::string type;
  std::string path;
};

class Mesh {
 public:
  Mesh(std::vector<Vertex>, std::vector<unsigned int>, std::vector<MeshTexture>);

  void Draw(Shader&);

 private:
  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<MeshTexture> textures;

  void setupMesh();
};