#pragma once

#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "glm/gtc/matrix_transform.hpp"
#include "Camera.h"
#include "Shader.h"
#include "stb_image.h"
#include "Texture.h"

bool firstMouseMovement = true;
float xPos = 400, yPos = 300;
float yaw = -90, pitch = 0;

//void MouseMove(float xPos, float yPos) {
//  if (firstMouseMovement) {
//    lastX = xPos;
//    lastY = yPos;
//
//    firstMouseMovement = false;
//  } 
//  float xoffset = xPos - lastX;
//  float yoffset = lastY - yPos;
//
//  lastX = xPos;
//  lastY = yPos;
//
//  const float sensitivity = 0.1f;
//  xoffset *= sensitivity;
//  yoffset *= sensitivity;
//
//  yaw += xoffset;
//  pitch += yoffset;
//
//  if (pitch > 70.0f) pitch = 70.0f;
//  if (pitch < -70.0f) pitch = -70.0f;
//}


int main() {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.majorVersion = 4;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;

  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "First Window",
                          sf::Style::Titlebar | sf::Style::Close);

  // window.setMouseCursorVisible(false);

  // window.setMouseCursorGrabbed(true);

  glewExperimental = GL_TRUE;

  if (GLEW_OK != glewInit()) {
    std::cout << "Error:: glew not init =(" << std::endl;
    return -1;
  }

  Shader myShader("res/shaders/e4.vs", "res/shaders/e4.fs");

  Camera camera;
  float speed = 0.1;

  float vertices[] = {-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, -0.5f, 0.5f,
                      0.0f,  0.0f,  1.0f,  0.5f, 0.5f, 0.0f,  1.0f,
                      1.0f,  0.5f,  -0.5f, 0.0f, 1.0f, 0.0f};

  unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                        (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(true);

  unsigned char* data =
      stbi_load("res/imgs/1.jpg", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(data);

  bool isGo = true;
  while (isGo) {
    sf::Event windowEvent;
    while (window.pollEvent(windowEvent)) {
      /*auto mouse_position = sf::Mouse::getPosition(window); 
      MouseMove(mouse_position.x, mouse_position.y);

      Vec3 direction;
      direction[0] = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
      direction[1] = sin(glm::radians(pitch));
      direction[2] = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
      camera.SetVecFront(direction.Normalize());*/

      switch (windowEvent.type) {
        case sf::Event::Closed:
          isGo = false;
          break;
        case sf::Event::KeyPressed:
          if (windowEvent.key.code == sf::Keyboard::A) {
            camera.Move((camera.GetVecFront().GetVectorProductWith(camera.GetVecUp())).Normalize() * (-1) * speed);
          }
          if (windowEvent.key.code == sf::Keyboard::W) {
            camera.Move(camera.GetVecFront() * speed);
          }
          if (windowEvent.key.code == sf::Keyboard::S) {
            camera.Move(camera.GetVecFront() * (-1) * speed);
          }
          if (windowEvent.key.code == sf::Keyboard::D) {
            camera.Move((camera.GetVecFront().GetVectorProductWith(camera.GetVecUp())).Normalize() * speed);
          }
        case sf::Event::MouseMoved:
          float xOffset = sf::Mouse::getPosition(window).x - xPos;
          float yOffset = yPos - sf::Mouse::getPosition(window).y;
          xPos = sf::Mouse::getPosition(window).x;
          yPos = sf::Mouse::getPosition(window).y;

          yaw += (xOffset * speed);
          pitch += (yOffset * speed);

          Vec3 front;
          front[0] = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
          front[1] = sin(glm::radians(pitch));
          front[2] = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
          camera.SetVecFront(front.Normalize());
          break;
      }
    }
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, texture);

    myShader.use();
    
    glBindVertexArray(VAO);

    myShader.setMat4("model", Mat4::GetIdentityMatrix());
    myShader.setMat4("view", camera.GetViewMatrix());
    myShader.setMat4("projection", camera.GetProjectionMatrix());

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    window.display();
  }

  window.close();
  return 0;
}