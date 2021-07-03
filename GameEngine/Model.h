#pragma once

#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Shader.h"
#include "Mesh.h"

class Model {
 public:
  Model(char*, bool);
  void Draw(Shader&);

 private:
  std::vector<Mesh> meshes;
  std::string directory;
  std::vector<Texture> textures_loaded;
  
  bool gammaCorrection;

  void loadModel(std::string path);

  void processNode(aiNode*, const aiScene*);

  Mesh processMesh(aiMesh*, const aiScene*);

  std::vector<Texture> loadMaterialTextures(aiMaterial*, aiTextureType, std::string);
};