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

bool firstMouseMovement = true;
float lastX = 400, lastY = 300;
float yaw = -90, pitch = 0;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

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

int main() {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.majorVersion = 4;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;

  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "First Window",
                          sf::Style::Titlebar | sf::Style::Close);

  window.setMouseCursorVisible(false);

  window.setMouseCursorGrabbed(true);

  glewExperimental = GL_TRUE;

  if (GLEW_OK != glewInit()) {
    std::cout << "Error:: glew not init =(" << std::endl;
    return -1;
  }

  Shader myShader("res/shaders/e4.vs", "res/shaders/e4.fs");
  Shader lightingShader("res/shaders/colors.vs", "res/shaders/colors.fs");
  Shader lampShader("res/shaders/lamp.vs", "res/shaders/lamp.fs");

  Camera camera;
  float speed = 0.1;

      float vertices[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
      };

  unsigned int indices[] = {0, 1, 3, 1, 2, 3};

  // 1. Настраиваем VAO (и VBO)
  unsigned int VBO, cubeVAO;
  glGenVertexArrays(1, &cubeVAO);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(cubeVAO);

  // Координатные атрибуты
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // 2. Настраиваем VAO света (VBO остается неизменным; вершины те же и для
  // светового объекта, который также является 3D-кубом)
  unsigned int lightVAO;
  glGenVertexArrays(1, &lightVAO);
  glBindVertexArray(lightVAO);

  // Нам нужно только привязаться к VBO (чтобы связать его с
  // glVertexAttribPointer), нам не нужно его заполнять; данные VBO уже содержат
  // всё, что нам нужно (они уже привязаны, но мы делаем это снова в
  // образовательных целях)
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

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
        case sf::Event::MouseMoved:


          break;
        default:
          break;
      }
    }

    // Рендеринг
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Убеждаемся, что активировали шейдер прежде, чем настраивать
    // uniform-переменные/объекты_рисования
    lightingShader.use();
    lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    lightingShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

    lightingShader.setMat4("projection", camera.GetProjectionMatrix());
    lightingShader.setMat4("view", camera.GetViewMatrix());

     glm::mat4 model = glm::mat4(1.0f);
    lightingShader.setMat4("model", model);

    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    lampShader.use();
    lampShader.setMat4("projection", camera.GetProjectionMatrix());
    lampShader.setMat4("view", camera.GetViewMatrix());
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));  // куб меньшего размера
    lampShader.setMat4("model", model);

    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);

    ////glBindTexture(GL_TEXTURE_2D, texture);

    //myShader.use();

    //glm::mat4 model = glm::mat4(1.0f);

    //myShader.setMat4("model", model);
    //myShader.setMat4("view", camera.GetViewMatrix());
    //myShader.setMat4("projection", camera.GetProjectionMatrix());

    //glBindVertexArray(VAO);

    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    window.display();
  }

  glDeleteVertexArrays(1, &cubeVAO);
  glDeleteVertexArrays(1, &lightVAO);
  glDeleteBuffers(1, &VBO);

  window.close();
  return 0;
}