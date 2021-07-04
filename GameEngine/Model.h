#pragma once

#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "Mesh.h"
#include "Shader.h"
#include "stb_image.h"
#include "math.h"


class Model {
 public:
  Model(const std::string&, bool gamma = false);

  void Draw(Shader);

 private:
  std::vector<MeshTexture> textures_loaded;
  std::vector<Mesh> meshes;
  std::string directory;
  bool gammaCorrection;

  void loadModel(std::string const&);

  void processNode(aiNode*, const aiScene*);

  Mesh processMesh(aiMesh*, const aiScene*);

  std::vector<MeshTexture> loadMaterialTextures(aiMaterial*,
                                                aiTextureType,
                                                std::string);

  unsigned int TextureFromFile(const char*, const std::string&,
                               bool gamma = false);
};