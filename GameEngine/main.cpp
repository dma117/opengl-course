﻿#pragma once

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

  glEnable(GL_DEPTH_TEST);

  Shader myShader("res/shaders/e4.vs", "res/shaders/e4.fs");
  Shader cubeLightingShader("res/shaders/colors.vs", "res/shaders/colors.fs");
  Shader lampShader("res/shaders/lamp.vs", "res/shaders/lamp.fs");

  Camera camera;
  float speed = 0.1;
  Texture wooden_full("res/imgs/wooden_full.png");
  Texture wooden("res/imgs/wooden.png");

  float vertices[] = {
         // координаты        // нормали           // текстурные координаты
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f
  };

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
	
	
  // Координаты всех контейнеров
  glm::vec3 cubePositions[] = {
      glm::vec3(0.0f,  0.0f,  0.0f),
      glm::vec3(2.0f,  5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f),
      glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3(2.4f, -0.4f, -3.5f),
      glm::vec3(-1.7f,  3.0f, -7.5f),
      glm::vec3(1.3f, -2.0f, -2.5f),
      glm::vec3(1.5f,  2.0f, -2.5f),
      glm::vec3(1.5f,  0.2f, -1.5f),
      glm::vec3(-1.3f,  1.0f, -1.5f) 
  };

  // Координаты точечных источников света
  glm::vec3 pointLightPositions[] = {
      glm::vec3(0.7f,  0.2f,  2.0f),
      glm::vec3(2.3f, -3.3f, -4.0f),
      glm::vec3(-4.0f,  2.0f, -12.0f),
      glm::vec3(0.0f,  0.0f, -3.0f)
  };

   // Сообщаем stb_image.h, чтобы он перевернул загруженные текстуры относительно
  // y-оси (до загрузки модели)
  stbi_set_flip_vertically_on_load(true);

  // Конфигурирование глобального состояния OpenGL
  glEnable(GL_DEPTH_TEST);

  // Компилирование нашей шейдерной программы
  Shader ourShader("res/shaders/model.vs", "res/shaders/model.fs");

  // Загрузка моделей
  Model ourModel("res/3d_models/backpack.obj");

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

    // Убеждаемся, что активировали шейдер прежде, чем настраивать
    // uniform-переменные/объекты_рисования
    ourShader.use();

    // Преобразования Вида/Проекции
    glm::mat4 view = camera.GetViewMatrix();
    ourShader.setMat4("projection", camera.GetProjectionMatrix());
    ourShader.setMat4("view", view);

    // Рендеринг загруженной модели
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(
        model,
        glm::vec3(0.0f, 0.0f, 0.0f));  // смещаем вниз чтобы быть в центре сцены
    model = glm::scale(
        model,
        glm::vec3(1.0f, 1.0f, 1.0f));  // объект слишком большой для нашей
                                       // сцены, поэтому немного уменьшим его
    ourShader.setMat4("model", model);
    ourModel.Render(ourShader);

    window.display();
  }

  window.close();
  return 0;
}