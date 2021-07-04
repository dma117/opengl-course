#pragma once

#include <string>
#include <vector>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "Shader.h"

struct Vertex {
  glm::vec3 Position;
  glm::vec3 Normal;
  glm::vec2 TexCoords;
  glm::vec3 Tangent;
  glm::vec3 Bitangent;
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