//� �������� e4.vs ���� ����� �������� ���

/*
#pragma once

#include <iostream>

// glew
#include <GL/glew.h>

// sfml
#include <SFML/Window.hpp>

//stb
#include "stb_image.h"

#include "shader.h"

//glm
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// ��������� ����� ������ ��� ������
class Camera {
 public:
  enum class ProjectionMode { ORTHOGRAPHIC, PERSPECTIVE };
  Camera() {
    m_viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f),
                    glm::vec3(0.0f, 1.0f, 0.0f));

    m_projectionMatrix = glm::ortho(-4.0f / 3.0f, 4.0f / 3.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    m_modelMatrix = glm::mat4(1.f);
  }

  float GetFov() const;
  float GetRatio() const;
  float GetNear() const;
  float GetFar() const;
  void SetFov(float p_value);
  void SetRatio(float p_value);
  void SetNear(float p_value);
  void SetFar(float p_value);

  const glm::mat4& GetProjectionMatrix() const { return m_viewMatrix; }
  const glm::mat4& GetViewMatrix() const { return m_projectionMatrix; }
  glm::mat4& GetModelMatrix() { return m_modelMatrix; }

 private:
  glm::mat4 m_viewMatrix;
  glm::mat4 m_projectionMatrix;
  glm::mat4 m_modelMatrix;
  ProjectionMode m_projectionMode;

  float m_fov;
  float m_ratio;
  float m_near;
  float m_far;
};

int main() {
  int nrAttributes;
  glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
  std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes
            << std::endl;

  sf::ContextSettings settings;
  settings.depthBits = 24;  // ���������� ����� ������� �������
  settings.stencilBits =
      8;  //���������� ����� ������ ���������, ������������ � ������� �������
          //��� ����������� ������� ����������
  settings.majorVersion = 4;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;

  // sf::VideoMode(������, ������, ���-�� ����� ��� ����� �� 1 �������)
  sf::Window window(sf::VideoMode(800, 600, 32), "First Window",
                    sf::Style::Titlebar | sf::Style::Close);

  glewExperimental = GL_TRUE;  // �������� ��� ����������� ������� ogl

  if (GLEW_OK != glewInit()) {  // �������� glew
    std::cout << "Error:: glew not init =(" << std::endl;
    return -1;
  }

  auto shaderProgram = Shader("shaders/e4.vs", "shaders/e4.fs");
  Camera camera;

  // glm::mat4& model = camera.GetModelMatrix();
  //model = glm::translate(model, glm::vec3(0.9f, 0.9f, 1.f));  // TODO
  //model = glm::rotate(model, 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));

  //auto& view = camera.GetViewMatrix();

  //auto& prj = camera.GetProjectionMatrix();

  //shaderProgram.setMat4("view", view);
  //shaderProgram.setMat4("prj", prj);
  //shaderProgram.setMat4("model", model);

  //= <YOUR CODE>

  float vertices[] = {
      // x      y     z      u     v
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  // ����� ������
      -0.5f, 0.5f,  0.0f, 0.0f, 1.0f,  // ����� �������
      0.5f,  0.5f,  0.0f, 1.0f, 1.0f,  // ������ �������
      0.5f,  -0.5f, 0.0f, 1.0f, 0.0f   // ������ ������
  };

  // EBO �������� ������������ ���� � �� �� ������� � ������ �������������
  unsigned int indices[] = {
      0, 1, 3,  // ������ �����������
      1, 2, 3   // ������ �����������
  };

  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(
      1, &VAO);  // ��������� id ��� �������� ������ (� ��� ��� ���� id)
  glBindVertexArray(VAO);  // � ������� ������ � opengl

  glGenBuffers(1, &VBO);  // ��������� ����� ������ �������� 1
  glBindBuffer(GL_ARRAY_BUFFER, VBO);  // � ������� ����� � opengl
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
               GL_STATIC_DRAW);  // ��������� ��� ����� ������ � opengl

  //������� � ������� EBO
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                        (void*)0);  // ��������� ��������� ��� �������
  glEnableVertexAttribArray(0);  //�� layout � ������� 0

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                        (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // �������� � �������� ��������
  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D,
                texture);  // ��� ����������� GL_TEXTURE_2D-�������� ������
                           // ����� ������ �� ������ ���������� ������

  // ��������� ���������� ��������� ��������
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // ���������
  // ������ ��������� �������� GL_REPEAT (����������� ����� ���������)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // ��������� ���������� ���������� ��������
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // �������� �����������, �������� �������� � ������������� ������-�������
  int width, height, nrChannels;
  /*
   * �� ������� �������� ����������� ����� ������.
   * ��� ���������� ������, ��� OpenGL �������, ��� ���������� 0.0 �� ��� Y
   * ����� ���������� � ������ ����� �����������, �� ����������� ������ �����
   * 0.0 � ������� ����� ��� Y. stbi_set_flip_vertically_on_load �������� ���!
   */
   //fstbi_set_flip_vertically_on_load(true);

    /*
  unsigned char* data =
      stbi_load("D:/Downloads/���������.jpg", &width, &height, &nrChannels, 0);
   if (data) {
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                  GL_UNSIGNED_BYTE, data);
     glGenerateMipmap(GL_TEXTURE_2D);
   } else {
     std::cout << "Failed to load texture" << std::endl;
   }
   stbi_image_free(data);

  // ���� �������
  bool isGo = true;
  while (isGo) {
    // ��������� ������� �� SFML (��� � ���� � ������� ��������������)
    sf::Event windowEvent;
    while (window.pollEvent(windowEvent)) {  // ��������� �������

      //<YOUR CODE>
      //��������� ������ � ���������� ������� ������
      //��������� ���� � ���������� �������� ������ �������� � ������� �����
      //������
      switch (windowEvent.type) {
        case sf::Event::Closed:
          isGo = false;
          break;
        default:
          break;
      }
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  //������ ���� ��������
    glClear(GL_COLOR_BUFFER_BIT);          //�������� ������

    glBindTexture(GL_TEXTURE_2D, texture);  //������� ��������

    shaderProgram.use();  // ���������� ������ ��������� ���������

    glm::mat4& model = camera.GetModelMatrix();
    model = glm::translate(model, glm::vec3(0.1f, 0.2f, 0.5f));  // TODO
    model = glm::rotate(model, 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));

    auto& view = camera.GetViewMatrix();

    auto& prj = camera.GetProjectionMatrix();

    shaderProgram.setMat4("view", view);
    shaderProgram.setMat4("projection", prj);
    shaderProgram.setMat4("model", model);

    glBindVertexArray(VAO);  // ���������� ������ ������ ��� ����������
    glDrawArrays(GL_TRIANGLES, 0, 6); //����������

    

   /* GLint Model = glGetUniformLocation(shaderProgram.ID, "model");
    glUniformMatrix4fv(Model, 1, GL_FALSE, glm::value_ptr(model));
    GLint View = glGetUniformLocation(shaderProgram.ID, "view");
    glUniformMatrix4fv(View, 1, GL_FALSE, glm::value_ptr(view));
    GLint Projection = glGetUniformLocation(shaderProgram.ID, "projection");
    glUniformMatrix4fv(Projection, 1, GL_FALSE, glm::value_ptr(prj));*/

    //��� ��������� � EBO ����������� glDrawElements
 /*   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    window.display();
  }

  window.close();
  return 0;
}*/
