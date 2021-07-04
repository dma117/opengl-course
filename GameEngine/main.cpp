#pragma once

#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"
#include "Camera.h"
#include "Shader.h"
#include "stb_image.h"
#include "Texture.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Model.h"

bool firstMouseMovement = true;
float lastX = 400, lastY = 300;
float yaw = -90, pitch = 0;

void MouseMove(float xPos, float yPos) {
  if (firstMouseMovement) {
    lastX = xPos;
    lastY = yPos;

    firstMouseMovement = false;
  } 
  float xoffset = xPos - lastX;
  float yoffset = lastY - yPos;

  lastX = xPos;
  lastY = yPos;

  const float sensitivity = 0.1f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw += xoffset;
  pitch += yoffset;

  if (pitch > 70.0f) pitch = 70.0f;
  if (pitch < -70.0f) pitch = -70.0f;
}

unsigned int loadCubemap(std::vector<std::string> faces) {
  unsigned int textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

  int width, height, nrChannels;
  for (unsigned int i = 0; i < faces.size(); i++) {
    unsigned char* data =
        stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
    if (data) {
      glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height,
                   0, GL_RGB, GL_UNSIGNED_BYTE, data);
      stbi_image_free(data);
    } else {
      std::cout << "Cubemap texture failed to load at path: " << faces[i]
                << std::endl;
      stbi_image_free(data);
    }
  }
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  return textureID;
}

int main() {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8; 
  settings.majorVersion = 4;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;

  sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "First Window",
                          sf::Style::Titlebar | sf::Style::Close, settings);

  //window.setMouseCursorVisible(false);
  //window.setMouseCursorGrabbed(true);

  glewExperimental = GL_TRUE;

  if (GLEW_OK != glewInit()) {
    std::cout << "Error:: glew not init =(" << std::endl;
    return -1;
  }

  unsigned int indices[] = {
      0, 1, 2, 
      0, 2, 3,

      4, 5, 6,
      4, 6, 7,

      8, 9, 10,
      8, 10, 11,

      12, 13, 14,
      12, 14, 15,

      16, 17, 18,
      16, 18, 19,

      20, 21, 22,
      20, 22, 23
  };

  // Координаты точечных источников света
  glm::vec3 modelPositions[] = {
      glm::vec3(0.7f,  0.2f,  2.0f),
      glm::vec3(2.3f, -3.3f, -4.0f),
      glm::vec3(-4.0f,  2.0f, -12.0f),
      glm::vec3(0.0f,  0.0f, -3.0f)
  };

  float skyboxVertices[] = {
	-1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, -1.0f,
	 1.0f, 1.0f, 1.0f,

	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, 1.0f,
	 1.0f, -1.0f, -1.0f,
   	 1.0f, -1.0f, 1.0f,
  };

  unsigned int skyboxIndices[] = {
  	0, 1, 2,
	1, 2, 3,

	4, 5, 6,
	5, 6, 7,

	0, 1, 5,
	0, 4, 5,

	2, 3, 7,
	2, 6, 7,

	0, 2, 6,
	0, 4, 6,

	1, 5, 7,
	1, 3, 7
  };


  std::vector<std::string> faces = {
   "res/skyboxes/sky/right.jpg",
   "res/skyboxes/sky/left.jpg",
   "res/skyboxes/sky/top.jpg",
   "res/skyboxes/sky/bottom.jpg",
   "res/skyboxes/sky/front.jpg",
   "res/skyboxes/sky/back.jpg"
  };

  Shader skyboxShader("res/shaders/skybox.vs", "res/shaders/skybox.fs");
  Shader modelShader("res/shaders/model.vs", "res/shaders/model.fs");
  Model ourModel("res/3d_models/backpack.obj");

  unsigned int cubemapTexture = loadCubemap(faces);
  
  Camera camera;
  float speed = 0.1;
  
  stbi_set_flip_vertically_on_load(true);

  glEnable(GL_DEPTH_TEST);

  VBO skyboxVBO(skyboxVertices, sizeof(skyboxVertices) / sizeof(float));
  VAO skyboxVAO;
  EBO skyboxEBO(skyboxIndices, sizeof(skyboxIndices) / sizeof(unsigned int));
  skyboxVAO.EnableArray(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  skyboxVBO.Bind();

  skyboxShader.use();
  skyboxShader.setInt("skybox", 0);

  bool isGo = true;
  while (isGo) {
    sf::Event windowEvent;
    while (window.pollEvent(windowEvent)) {
      auto mouse_position = sf::Mouse::getPosition(); 
      MouseMove(mouse_position.x, mouse_position.y);

      glm::vec3 direction;
      direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
      direction.y = sin(glm::radians(pitch));
      direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
      camera.SetVecFront(glm::normalize(direction));

      switch (windowEvent.type) {
        case sf::Event::Closed:
          isGo = false;
          break;
        case sf::Event::KeyPressed:
          if (windowEvent.key.code == sf::Keyboard::A) {
            camera.Move(-glm::normalize(glm::cross(camera.GetVecFront(), camera.GetVecUp())) * speed);
          }
          if (windowEvent.key.code == sf::Keyboard::W) {
            camera.Move(camera.GetVecFront() * speed);
          }
          if (windowEvent.key.code == sf::Keyboard::S) {
            camera.Move(-camera.GetVecFront() * speed);
          }
          if (windowEvent.key.code == sf::Keyboard::D) {
            camera.Move(glm::normalize(glm::cross(camera.GetVecFront(),camera.GetVecUp())) * speed);
          }
          break;
        default:
          break;
      }
    }
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    modelShader.use();
    modelShader.setMat4("projection", camera.GetProjectionMatrix());
    modelShader.setMat4("view", camera.GetViewMatrix());

    for (int i = 0; i < 4; i++) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, modelPositions[i]);
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        modelShader.setMat4("model", model);
        ourModel.Draw(modelShader);
    }

    glDepthFunc(GL_LEQUAL);
    skyboxShader.use();
    skyboxShader.setMat4("view", glm::mat4(glm::mat3(camera.GetViewMatrix())));
    skyboxShader.setMat4("projection", camera.GetProjectionMatrix());

    skyboxVAO.Bind();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS);

    window.display();
  }

  window.close();
  return 0;
}