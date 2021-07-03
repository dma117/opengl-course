#pragma once

#include "glm/glm.hpp"
#include <string>
#include <vector>
#include "Shader.h"
#include "SctructuralUnits.h" 

class Mesh {
 public:
  Mesh(std::vector<Vertex>, std::vector<unsigned int>, std::vector<Texture>);

  void Draw(Shader);

  private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};
