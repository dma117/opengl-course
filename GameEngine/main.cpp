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
  Shader lightingShader("res/shaders/colors.vs", "res/shaders/colors.fs");
  Shader lampShader("res/shaders/lamp.vs", "res/shaders/lamp.fs");

  Camera camera;
  float speed = 0.1;
  Texture wooden_full("res/imgs/wooden_full.png");
  Texture wooden("res/imgs/wooden.png");

  // Указание вершин (и буфера(ов)) и настройка вершинных атрибутов
    float vertices[] = {
         // координаты        // нормали           // текстурные координаты
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
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
        
  // 1. Настраиваем VAO (и VBO) куба
    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // 2. Настраиваем VAO света (VBO остается неизменным; вершины те же и для светового объекта, который также является 3D-кубом)
    unsigned int lightCubeVAO;;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Обратите внимание, что мы обновляем шаг атрибута положения лампы, чтобы отразить обновленные данные буфера
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
	
    // Конфигурация шейдеров
    lightingShader.use();
    lightingShader.setInt("material.diffuse", 0);
    lightingShader.setInt("material.specular", 1);

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

    // Рендеринг
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Убеждаемся, что активировали шейдер прежде, чем настраивать
    // uniform-переменные/объекты_рисования
    lightingShader.use();
    lightingShader.setVec3("viewPos", camera.GetPosition());
    lightingShader.setFloat("material.shininess", 32.0f);

    // Направленный свет
    lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
    lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
    lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
    lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

    // Точечный источник света №1
    lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
    lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
    lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
    lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
    lightingShader.setFloat("pointLights[0].constant", 1.0f);
    lightingShader.setFloat("pointLights[0].linear", 0.09);
    lightingShader.setFloat("pointLights[0].quadratic", 0.032);

    // Точечный источник света №2
    lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
    lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
    lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
    lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
    lightingShader.setFloat("pointLights[1].constant", 1.0f);
    lightingShader.setFloat("pointLights[1].linear", 0.09);
    lightingShader.setFloat("pointLights[1].quadratic", 0.032);

    // Точечный источник света №3
    lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
    lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
    lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
    lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
    lightingShader.setFloat("pointLights[2].constant", 1.0f);
    lightingShader.setFloat("pointLights[2].linear", 0.09);
    lightingShader.setFloat("pointLights[2].quadratic", 0.032);

    // Точечный источник света №4
    lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
    lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
    lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
    lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
    lightingShader.setFloat("pointLights[3].constant", 1.0f);
    lightingShader.setFloat("pointLights[3].linear", 0.09);
    lightingShader.setFloat("pointLights[3].quadratic", 0.032);

    // Прожектор
    lightingShader.setVec3("spotLight.position", camera.GetPosition());
    lightingShader.setVec3("spotLight.direction", camera.GetVecFront());
    lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    lightingShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
    lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
    lightingShader.setFloat("spotLight.constant", 1.0f);
    lightingShader.setFloat("spotLight.linear", 0.09);
    lightingShader.setFloat("spotLight.quadratic", 0.032);
    lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    lightingShader.setFloat("spotLight.outerCutOff",
                            glm::cos(glm::radians(15.0f)));

    lightingShader.setMat4("projection", camera.GetProjectionMatrix());
    lightingShader.setMat4("view", camera.GetViewMatrix());

    // Мировое преобразование
    glm::mat4 model = glm::mat4(1.0f);
    lightingShader.setMat4("model", model);

    // Связывание диффузной карты
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, wooden_full.GetTextureId());

    // Связывание карты отраженного цвета
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, wooden.GetTextureId());

    // Рендеринг контейнеров
    glBindVertexArray(cubeVAO);
    for (unsigned int i = 0; i < 10; i++) {
      // Вычисляем матрицу модели для каждого объекта и передаем её в шейдер
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, cubePositions[i]);
      float angle = 20.0f * i;
      model =
          glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      lightingShader.setMat4("model", model);

      glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    // Также отрисовываем объект лампы
    lampShader.use();
    lampShader.setMat4("projection", camera.GetProjectionMatrix());
    lampShader.setMat4("view", camera.GetViewMatrix());

    // А теперь мы отрисовываем столько ламп, сколько у нас есть точечных
    // источников света
    glBindVertexArray(lightCubeVAO);
    for (unsigned int i = 0; i < 4; i++) {
      model = glm::mat4(1.0f);
      model = glm::translate(model, pointLightPositions[i]);
      model = glm::scale(model, glm::vec3(0.2f));  // меньший куб
      lampShader.setMat4("model", model);
      glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    window.display();
  }

   // Опционально: освобождаем все ресурсы, как только они выполнили свое
  // предназначение
  glDeleteVertexArrays(1, &cubeVAO);
  glDeleteVertexArrays(1, &lightCubeVAO);
  glDeleteBuffers(1, &VBO);

  window.close();
  return 0;
}