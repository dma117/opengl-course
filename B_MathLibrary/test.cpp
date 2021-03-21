#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "math.h"
#define EPS 0.0001


TEST_CASE("Class Vec2 testing", "[Vec2]") {
  SECTION("Vec2 Constructors") {
    {
      const Vec2 my_vector(5);
      const glm::vec2 glm_vector(5);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      const Vec2 my_vector(5, 1);
      const glm::vec2 glm_vector(5, 1);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      const Vec2 my_vector(5, 1);
      const Vec2 my_vector_copy(my_vector);

      const glm::vec2 glm_vector(5, 1);
      const glm::vec2 glm_vector_copy(glm_vector);

      REQUIRE(my_vector_copy[0] == glm_vector_copy[0]);
      REQUIRE(my_vector_copy[1] == glm_vector_copy[1]);
    }
  }

  SECTION("Vec2 operations") {
    {
      const Vec2 my_vec1(5);
      const Vec2 my_vec2(1, 17);

      const glm::vec2 glm_vec1(5);
      const glm::vec2 glm_vec2(1, 17);

      const Vec2 my_result = my_vec1 + my_vec2;
      const glm::vec2 glm_result = glm_vec1 + glm_vec2;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const Vec2 my_vec1(5);
      const Vec2 my_vec2(1, 17);

      const glm::vec2 glm_vec1(5);
      const glm::vec2 glm_vec2(1, 17);

      const Vec2 my_result = my_vec1 - my_vec2;
      const glm::vec2 glm_result = glm_vec1 - glm_vec2;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const Vec2 my_vector(7, 1);
      const glm::vec2 glm_vector(7, 1);

      const Vec2 my_result = my_vector * 5.5f;
      const glm::vec2 glm_result = glm_vector * 5.5f;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const Vec2 my_vector(7, 1);
      const glm::vec2 glm_vector(7, 1);

      const Vec2 my_result = my_vector / 5.5f;
      const glm::vec2 glm_result = glm_vector / 5.5f;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      Vec2 my_vector(7, 1);
      glm::vec2 glm_vector(7, 1);

      my_vector += 5.5f;
      glm_vector += 5.5f;

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      Vec2 my_vector(7, 1);
      glm::vec2 glm_vector(7, 1);

      my_vector -= 5.5f;
      glm_vector -= 5.5f;

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      Vec2 my_vector(7, 1);
      glm::vec2 glm_vector(7, 1);

      my_vector *= 5.5f;
      glm_vector *= 5.5f;

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      Vec2 my_vector(-222.7, 1);
      glm::vec2 glm_vector(-222.7, 1);

      my_vector /= 5.5f;
      glm_vector /= 5.5f;

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      const Vec2 vec_1;
      const Vec2 vec_2;
      REQUIRE(vec_1 == vec_2);
    }
    {
      const Vec2 vec_1(1.1, 2);
      const Vec2 vec_2(1.1, 2);
      REQUIRE(vec_1 == vec_2);
    }
    {
      const Vec2 vec_1;
      const Vec2 vec_2;
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      const Vec2 vec_1(1.1, 2);
      const Vec2 vec_2(1.1, 2);
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      Vec2 vec_1(115, -9);
      Vec2 vec_2(115, -9);

      REQUIRE(vec_1[0] == vec_2[0]);
      REQUIRE(vec_1[1] == vec_2[1]);
    }
  }

  SECTION("Vec2 functions") {
    {
      const Vec2 my_vector(5, 5);
      const glm::vec2 glm_vector(5, 6);

      REQUIRE_FALSE(my_vector.Length() == glm::length(glm_vector));
    }
    {
      const Vec2 my_vector;
      const glm::vec2 glm_vector;

      // REQUIRE(my_vector.length() == glm::length(glm_vector));
    }
    {
      const Vec2 my_vector(-4);
      const glm::vec2 glm_vector(-4);

      REQUIRE(my_vector.Length() == Approx(glm::length(glm_vector)).epsilon(EPS));
    }
    {
      const Vec2 my_vec1(-4, 15);
      const Vec2 my_vec2(1, -8);

      const glm::vec2 glm_vec1(-4, 15);
      const glm::vec2 glm_vec2(1, -8);

      float first = my_vec1.GetScalarProductWith(my_vec2);
      float second = glm::dot(glm_vec1, glm_vec2);

      REQUIRE(first == second);
    }
    {
      const Vec2 my_vec1(-4, 15);
      const glm::vec2 glm_vec1(-4, 15);

      Vec2 n1 = my_vec1.Normalize();
      auto n2 = glm::normalize(glm_vec1);

      REQUIRE(n1[0] == n2[0]);
      REQUIRE(n1[1] == n2[1]);
    }
  }
}

TEST_CASE("Class Vec3 testing", "[Vec3]") {
  SECTION("Vec3 Constructors") {
    {
      const Vec3 my_vector(5);
      const glm::vec3 glm_vector(5);

      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
    }
    {
      const Vec3 my_vector(5, 1, 7);
      const glm::vec3 glm_vector(5, 1, 7);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
    }
    {
      const Vec3 my_vector(-5, 1, 0);
      const Vec3 my_vector_copy(my_vector);

      const glm::vec3 glm_vector(-5, 1, -0);
      const glm::vec3 glm_vector_copy(glm_vector);

      REQUIRE(my_vector_copy[0] == glm_vector_copy[0]);
      REQUIRE(my_vector_copy[1] == glm_vector_copy[1]);
      REQUIRE(my_vector_copy[2] == glm_vector_copy[2]);
    }
  }

  SECTION("Vec3 operations") {
    {
      const Vec3 my_vecA(5);
      const Vec3 my_vecB(1, 17, -1);

      const glm::vec3 glm_vecA(5);
      const glm::vec3 glm_vecB(1, 17, -1);

      const Vec3 my_result = my_vecA + my_vecB;
      const glm::vec3 glm_result = glm_vecA + glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
    }
    {
      const Vec3 my_vecA(5);
      const Vec3 my_vecB(1, 17, -1);

      const glm::vec3 glm_vecA(5);
      const glm::vec3 glm_vecB(1, 17, -1);

      const Vec3 my_result = my_vecA - my_vecB;
      const glm::vec3 glm_result = glm_vecA - glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
    }
    {
      const Vec3 my_vector(7, 1, -4.5);
      const glm::vec3 glm_vector(7, 1, -4.5);

      const Vec3 my_result = my_vector * 5.5f;
      const glm::vec3 glm_result = glm_vector * 5.5f;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
    }
    {
      const Vec3 my_vector(7, 1, -4.5);
      const glm::vec3 glm_vector(7, 1, -4.5);

      const Vec3 my_result = my_vector / 5.5f;
      const glm::vec3 glm_result = glm_vector / 5.5f;

      REQUIRE(my_result[0] == Approx(glm_result[0]).epsilon(EPS));
      REQUIRE(my_result[1] == Approx(glm_result[1]).epsilon(EPS));
      REQUIRE(my_result[2] == Approx(glm_result[2]).epsilon(EPS));
    }
    {
      Vec3 my_vector(7, 1, -4.5);
      glm::vec3 glm_vector(7, 1, -4.5);
      
      my_vector += 5.5f;
      glm_vector += 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
    }
    {
      Vec3 my_vector(7, 1, -4.5);
      glm::vec3 glm_vector(7, 1, -4.5);

      my_vector -= 5.5f;
      glm_vector -= 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
    }
    {
      Vec3 my_vector(7, 1, -4.5);
      glm::vec3 glm_vector(7, 1, -4.5);

      my_vector *= 5.5f;
      glm_vector *= 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
    }
    {
      Vec3 my_vector(7, 1, -4.5);
      glm::vec3 glm_vector(7, 1, -4.5);

      my_vector /= 5.5f;
      glm_vector /= 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
    }
    {
      const Vec3 vec_1;
      const Vec3 vec_2;
      REQUIRE(vec_1 == vec_2);
    }
    {
      const Vec3 vec_1(1.1, 2, -9.1);
      const Vec3 vec_2(1.1, 2, -9.1);
      REQUIRE(vec_1 == vec_2);
    }
    {
      const Vec3 vec_1;
      const Vec3 vec_2;
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      const Vec3 vec_1(1.1, 2, 5);
      const Vec3 vec_2(1.1, 2, 5);
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      Vec3 vec_1(115, -9, 2);
      Vec3 vec_2(115, -9, 2);

      REQUIRE(vec_1[0] == vec_2[0]);
      REQUIRE(vec_1[1] == vec_2[1]);
      REQUIRE(vec_1[2] == vec_2[2]);
    }
  }

  SECTION("Vec3 functions") {
    {
      const Vec3 my_vector(5, 6, 5);
      const glm::vec3 glm_vector(5, 6, 5);

      REQUIRE(my_vector.Length() == Approx(glm::length(glm_vector)).epsilon(EPS));
    }
    {
      const Vec3 my_vector;
      const glm::vec3 glm_vector;

      // REQUIRE(my_vector.Length() == glm::length(glm_vector));
    }
    {
      const Vec3 my_vector(-4);
      const glm::vec3 glm_vector(-4);

      REQUIRE(my_vector.Length() == Approx(glm::length(glm_vector)).epsilon(EPS));
    }
    {
      const Vec3 my_vec1(-4, 15, 87.4);
      const Vec3 my_vec2(1, -8, 12.125);

      const glm::vec3 glm_vec1(-4, 15, 87.4);
      const glm::vec3 glm_vec2(1, -8, 12.125);

      float first = my_vec1.GetScalarProductWith(my_vec2);
      float second = glm::dot(glm_vec1, glm_vec2);

      REQUIRE(first == Approx(second).epsilon(EPS));
    }
    {
      const Vec3 my_vec1(16.6, -4, 21);
      const glm::vec3 glm_vec1(16.6, -4, 21);

      Vec3 n1 = my_vec1.Normalize();
      glm::vec3 n2 = glm::normalize(glm_vec1);
      
      REQUIRE(n1[0] == Approx(n2[0]).epsilon(EPS));
      REQUIRE(n1[1] == Approx(n2[1]).epsilon(EPS));
      REQUIRE(n1[2] == Approx(n2[2]).epsilon(EPS));
    }
    {
      const Vec3 my_vec1(-4, 15, 87.4);
      const Vec3 my_vec2(1, -8, 12.125);

      const glm::vec3 glm_vec1(-4, 15, 87.4);
      const glm::vec3 glm_vec2(1, -8, 12.125);

      Vec3 first = my_vec1.GetVectorProductWith(my_vec2);
      glm::vec3 second = glm::cross(glm_vec1, glm_vec2);

      REQUIRE(first[0] == Approx(second[0]).epsilon(EPS));
      REQUIRE(first[1] == Approx(second[1]).epsilon(EPS));
      REQUIRE(first[2] == Approx(second[2]).epsilon(EPS));
    }
  }
}

TEST_CASE("Class Vec4 testing", "[Vec4]") {
  SECTION("Vec4 Constructors") {
    {
      const Vec4 my_vector(5);
      const glm::vec4 glm_vector(5);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
    }
    {
      const Vec4 my_vector(5, 1, 7, 8);
      const glm::vec4 glm_vector(5, 1, 7, 8);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
      REQUIRE(my_vector[3] == glm_vector[3]);
    }
    {
      const Vec4 my_vector(-5, 1, 0, 0);
      const Vec4 my_vector_copy(my_vector);

      const glm::vec4 glm_vector(-5, 1, -0, -0);
      const glm::vec4 glm_vector_copy(glm_vector);

      REQUIRE(my_vector_copy[0] == glm_vector_copy[0]);
      REQUIRE(my_vector_copy[1] == glm_vector_copy[1]);
      REQUIRE(my_vector_copy[2] == glm_vector_copy[2]);
      REQUIRE(my_vector_copy[3] == glm_vector_copy[3]);
    }
  }

  SECTION("Vec4 operations") {
    {
      const Vec4 my_vecA(5);
      const Vec4 my_vecB(1, 17, -1, 2);

      const glm::vec4 glm_vecA(5);
      const glm::vec4 glm_vecB(1, 17, -1, 2);

      const Vec4 my_result = my_vecA + my_vecB;
      const glm::vec4 glm_result = glm_vecA + glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
      REQUIRE(my_result[3] == glm_result[3]);
    }
    {
      const Vec4 my_vecA(5);
      const Vec4 my_vecB(1, 17, -1, 2);

      const glm::vec4 glm_vecA(5);
      const glm::vec4 glm_vecB(1, 17, -1, 2);

      const Vec4 my_result = my_vecA - my_vecB;
      const glm::vec4 glm_result = glm_vecA - glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
      REQUIRE(my_result[3] == glm_result[3]);
    }
    {
      const Vec4 my_vector(7, 1, -4.5, -1);
      const glm::vec4 glm_vector(7, 1, -4.5, -1);

      const Vec4 my_result = my_vector * 5.5f;
      const glm::vec4 glm_result = glm_vector * 5.5f;

      REQUIRE(my_result[0] == Approx(glm_result[0]).epsilon(EPS));
      REQUIRE(my_result[1] == Approx(glm_result[1]).epsilon(EPS));
      REQUIRE(my_result[2] == Approx(glm_result[2]).epsilon(EPS));
      REQUIRE(my_result[3] == Approx(glm_result[3]).epsilon(EPS));
    }
    {
      const Vec4 my_vector(7, 1, -4.5, -1);
      const glm::vec4 glm_vector(7, 1, -4.5, -1);

      const Vec4 my_result = my_vector / 5.5f;
      const glm::vec4 glm_result = glm_vector / 5.5f;

      REQUIRE(my_result[0] == Approx(glm_result[0]).epsilon(EPS));
      REQUIRE(my_result[1] == Approx(glm_result[1]).epsilon(EPS));
      REQUIRE(my_result[2] == Approx(glm_result[2]).epsilon(EPS));
      REQUIRE(my_result[3] == Approx(glm_result[3]).epsilon(EPS));
    }
    {
      Vec4 my_vector(7, 1, -4.5, -1);
      glm::vec4 glm_vector(7, 1, -4.5, -1);

      my_vector += 5.5f;
      glm_vector += 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
      REQUIRE(my_vector[3] == Approx(glm_vector[3]).epsilon(EPS));
    }
    {
      Vec4 my_vector(7, 1, -4.5, -1);
      glm::vec4 glm_vector(7, 1, -4.5, -1);

      my_vector -= 5.5f;
      glm_vector -= 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
      REQUIRE(my_vector[3] == Approx(glm_vector[3]).epsilon(EPS));
    }
    {
      Vec4 my_vector(7, 1, -4.5, -1);
      glm::vec4 glm_vector(7, 1, -4.5, -1);

      my_vector *= 5.5f;
      glm_vector *= 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
      REQUIRE(my_vector[3] == Approx(glm_vector[3]).epsilon(EPS));
    }
    {
      Vec4 my_vector(7, 1, -4.5, -1);
      glm::vec4 glm_vector(7, 1, -4.5, -1);

      my_vector /= 5.5f;
      glm_vector /= 5.5f;

      REQUIRE(my_vector[0] == Approx(glm_vector[0]).epsilon(EPS));
      REQUIRE(my_vector[1] == Approx(glm_vector[1]).epsilon(EPS));
      REQUIRE(my_vector[2] == Approx(glm_vector[2]).epsilon(EPS));
      REQUIRE(my_vector[3] == Approx(glm_vector[3]).epsilon(EPS));
    }
    {
      const Vec4 vec_1;
      const Vec4 vec_2;
      REQUIRE(vec_1 == vec_2);
    }
    {
      const Vec4 vec_1(1.1, 2, -9.1, 15.6);
      const Vec4 vec_2(1.1, 2, -9.1, 15.6);
      REQUIRE(vec_1 == vec_2);
    }
    {
      const Vec4 vec_1;
      const Vec4 vec_2;
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      const Vec4 vec_1(1.1, 2, 5, 3);
      const Vec4 vec_2(1.1, 2, 5, 3);
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      Vec4 vec_1(115, -9, 2, 900);
      Vec4 vec_2(115, -9, 2, 900);

      REQUIRE(vec_1[0] == vec_2[0]);
      REQUIRE(vec_1[1] == vec_2[1]);
      REQUIRE(vec_1[2] == vec_2[2]);
      REQUIRE(vec_1[3] == vec_2[3]);
    }
  }

  SECTION("Vec3 functions") {
    {
      const Vec4 my_vector(5, 6, 5, -7);
      const glm::vec4 glm_vector(5, 6, 5, -7);

      REQUIRE(my_vector.Length() == Approx(glm::length(glm_vector)).epsilon(EPS));
    }
    {
      const Vec4 my_vector;
      const glm::vec4 glm_vector;

      // REQUIRE(my_vector.Length() == glm::length(glm_vector));
    }
    {
      const Vec4 my_vector(-4);
      const glm::vec4 glm_vector(-4);

      REQUIRE(my_vector.Length() == glm::length(glm_vector));
    }
    {
      const Vec4 my_vec1(-4, 15, 87.4, 21.851);
      const Vec4 my_vec2(1, -8, 12.125, 21.851);

      const glm::vec4 glm_vec1(-4, 15, 87.4, 21.851);
      const glm::vec4 glm_vec2(1, -8, 12.125, 21.851);

      auto first = my_vec1.GetScalarProductWith(my_vec2);
      float second = glm::dot(glm_vec1, glm_vec2);

      REQUIRE(first == Approx(second).epsilon(EPS));
    }
    {
      const Vec4 my_vec1(-4.8, 15.1, 21.3, 5);
      const glm::vec4 glm_vec1(-4.8, 15.1, 21.3, 5);

      const Vec4 n1 = my_vec1.Normalize();
      const glm::vec4 n2 = glm::normalize(glm_vec1);

      REQUIRE(n1[0] == Approx(n2[0]).epsilon(EPS));
      REQUIRE(n1[1] == Approx(n2[1]).epsilon(EPS));
      REQUIRE(n1[2] == Approx(n2[2]).epsilon(EPS));
      REQUIRE(n1[3] == Approx(n2[3]).epsilon(EPS));
    }
  }
}

TEST_CASE("Class Mat2 testing", "[mat]") {
  SECTION("Mat2 constructors") {
    {
      const Mat2 my_mat(1);
      const glm::mat2 glm_mat(1);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
    }
    {
      const Mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
    }
    {
      const Mat2 my_mat(1, 2, 3, 4);
      const Mat2 my_mat_copy(my_mat);

      const glm::mat2 glm_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat_copy(glm_mat);

      REQUIRE(my_mat_copy[0][0] == glm_mat_copy[0][0]);
      REQUIRE(my_mat_copy[0][1] == glm_mat_copy[0][1]);
      REQUIRE(my_mat_copy[1][0] == glm_mat_copy[1][0]);
      REQUIRE(my_mat_copy[1][1] == glm_mat_copy[1][1]);
    }
    {
      const Mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
    }
  }

  SECTION("Mat2 operations") {
    {
      const Mat2 my_mat_1(1, 2, 3, 4);
      const Mat2 my_mat_2(3, 4, 5, 6);

      const auto my_result = my_mat_1 * my_mat_2;

      REQUIRE(my_result[0][0] == 13);
      REQUIRE(my_result[0][1] == 16);
      REQUIRE(my_result[1][0] == 29);
      REQUIRE(my_result[1][1] == 36);
    }
    {
      const Mat2 my_mat_1(1);
      const Mat2 my_mat_2(1);

      REQUIRE(my_mat_1[0][0] == my_mat_2[0][0]);
      REQUIRE(my_mat_1[0][1] == my_mat_2[0][1]);
      REQUIRE(my_mat_1[1][0] == my_mat_2[1][0]);
      REQUIRE(my_mat_1[1][1] == my_mat_2[1][1]);

      REQUIRE_FALSE(my_mat_1[0][0] != my_mat_2[0][0]);
      REQUIRE_FALSE(my_mat_1[0][1] != my_mat_2[0][1]);
      REQUIRE_FALSE(my_mat_1[1][0] != my_mat_2[1][0]);
      REQUIRE_FALSE(my_mat_1[1][1] != my_mat_2[1][1]);
    }
    {
      const Mat2 my_mat_1;
      const Mat2 my_mat_2;

      REQUIRE(my_mat_1[0][0] == my_mat_2[0][0]);
      REQUIRE(my_mat_1[0][1] == my_mat_2[0][1]);
      REQUIRE(my_mat_1[1][0] == my_mat_2[1][0]);
      REQUIRE(my_mat_1[1][1] == my_mat_2[1][1]);

      REQUIRE_FALSE(my_mat_1[0][0] != my_mat_2[0][0]);
      REQUIRE_FALSE(my_mat_1[0][1] != my_mat_2[0][1]);
      REQUIRE_FALSE(my_mat_1[1][0] != my_mat_2[1][0]);
      REQUIRE_FALSE(my_mat_1[1][1] != my_mat_2[1][1]);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);
      const Mat2 my_mat_2(1, 2, 3, 4);

      REQUIRE(my_mat_1[0][0] == my_mat_2[0][0]);
      REQUIRE(my_mat_1[0][1] == my_mat_2[0][1]);
      REQUIRE(my_mat_1[1][0] == my_mat_2[1][0]);
      REQUIRE(my_mat_1[1][1] == my_mat_2[1][1]);

      REQUIRE_FALSE(my_mat_1[0][0] != my_mat_2[0][0]);
      REQUIRE_FALSE(my_mat_1[0][1] != my_mat_2[0][1]);
      REQUIRE_FALSE(my_mat_1[1][0] != my_mat_2[1][0]);
      REQUIRE_FALSE(my_mat_1[1][1] != my_mat_2[1][1]);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);
      const Mat2 my_mat_2(3, 4, 5, 6);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);
      const glm::mat2 glm_mat_2(3, 4, 5, 6);

      const auto my_result = my_mat_1 + my_mat_2;
      const auto glm_result = glm_mat_1 + glm_mat_2;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);
      const Mat2 my_mat_2(3, 4, 5, 6);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);
      const glm::mat2 glm_mat_2(3, 4, 5, 6);

      const auto my_result = my_mat_1 - my_mat_2;
      const auto glm_result = glm_mat_1 - glm_mat_2;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 + 5;
      const auto glm_result = glm_mat_1 + 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 - 5;
      const auto glm_result = glm_mat_1 - 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 * 5;
      const auto glm_result = glm_mat_1 * 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 * Vec2(-3, -4);
      //const auto glm_result = glm_mat_1 * glm::vec2(-3, -4);

      REQUIRE(my_result[0] == -11);
      REQUIRE(my_result[1] == -25);
    }
    {
      const Mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 / 5;
      const auto glm_result = glm_mat_1 / 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
  }

  SECTION("Mat2 functions") {
    {
      const Mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat = glm::transpose(glm::mat2(1, 2, 3, 4));

      for (int i = 0; i < 2; i++) {
        const auto my_vec = my_mat.GetCol(i);
        const auto glm_vec = glm_mat[i];

        REQUIRE(my_vec[0] == glm_vec[0]);
        REQUIRE(my_vec[1] == glm_vec[1]);
      }
    }
    {
      const Mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      for (int i = 0; i < 2; i++) {
        const auto my_vec = my_mat.GetRow(i);
        const auto glm_vec = glm_mat[i];

        REQUIRE(my_vec[0] == glm_vec[0]);
        REQUIRE(my_vec[1] == glm_vec[1]);
      }
    }
    {
      const Mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      const Mat2 my_transpose_mat = my_mat.GetTransponed();
      const glm::mat2 glm_transpose_mat = glm::transpose(glm_mat);

      REQUIRE(my_transpose_mat[0][0] == glm_transpose_mat[0][0]);
      REQUIRE(my_transpose_mat[0][1] == glm_transpose_mat[0][1]);
      REQUIRE(my_transpose_mat[1][0] == glm_transpose_mat[1][0]);
      REQUIRE(my_transpose_mat[1][1] == glm_transpose_mat[1][1]);
    }
    {
      const Mat2 my_mat_1(-10.f, 944.4f, 5, 4);
      const Mat2 my_mat_2(-10.f, 944.4f, 5, 4);
      const Mat2 my_mat_3(10.f, -944.4f, -5, -4);

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE(my_mat_1 != my_mat_3);
    }
    {
      const Mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      float my_det = my_mat.GetDeterminant();
      float glm_det = glm::determinant(glm_mat);

      REQUIRE(my_det == glm_det);
    }
    {
         const Mat2 my_invertible_mat = Mat2(1, 2, 3, 4).GetInvertible();
         const glm::mat2 glm_invertible_mat = glm::inverse(glm::mat2(1, 2, 3, 4));

         REQUIRE(my_invertible_mat[0][0] == glm_invertible_mat[0][0]);
         REQUIRE(my_invertible_mat[0][1] == glm_invertible_mat[0][1]);
         REQUIRE(my_invertible_mat[1][0] == glm_invertible_mat[1][0]);
         REQUIRE(my_invertible_mat[1][1] == glm_invertible_mat[1][1]);
    } 
    {
      const Mat2 my_invertible_mat = Mat2(-9.9f, -2, 321, 43).GetInvertible();
      const glm::mat2 glm_invertible_mat = glm::inverse(glm::mat2(-9.9f, -2, 321, 43));

      REQUIRE(my_invertible_mat[0][0] == glm_invertible_mat[0][0]);
      REQUIRE(my_invertible_mat[0][1] == glm_invertible_mat[0][1]);
      REQUIRE(my_invertible_mat[1][0] == glm_invertible_mat[1][0]);
      REQUIRE(my_invertible_mat[1][1] == glm_invertible_mat[1][1]);
    } 
    {
      const Mat2 my_result = Mat2::GetIdentityMatrix();
      const glm::mat2 glm_result(1.0f);

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
  }
}

TEST_CASE("Class Mat3 testing", "[mat]") {
  SECTION("Mat3 constructors") {
    {
      const Mat3 my_mat(1);
      const glm::mat3 glm_mat(1);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[0][2] == glm_mat[0][2]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
      REQUIRE(my_mat[1][2] == glm_mat[1][2]);
      REQUIRE(my_mat[2][0] == glm_mat[2][0]);
      REQUIRE(my_mat[2][1] == glm_mat[2][1]);
      REQUIRE(my_mat[2][2] == glm_mat[2][2]);
    }
    {
      const Mat3 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[0][2] == glm_mat[0][2]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
      REQUIRE(my_mat[1][2] == glm_mat[1][2]);
      REQUIRE(my_mat[2][0] == glm_mat[2][0]);
      REQUIRE(my_mat[2][1] == glm_mat[2][1]);
      REQUIRE(my_mat[2][2] == glm_mat[2][2]);
    }
    {
      const Mat3 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const Mat3 my_mat_copy(my_mat);

      const glm::mat3 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3 glm_mat_copy(glm_mat);

      REQUIRE(my_mat_copy[0][0] == glm_mat_copy[0][0]);
      REQUIRE(my_mat_copy[0][1] == glm_mat_copy[0][1]);
      REQUIRE(my_mat_copy[0][2] == glm_mat_copy[0][2]);
      REQUIRE(my_mat_copy[1][0] == glm_mat_copy[1][0]);
      REQUIRE(my_mat_copy[1][1] == glm_mat_copy[1][1]);
      REQUIRE(my_mat_copy[1][2] == glm_mat_copy[1][2]);
      REQUIRE(my_mat_copy[2][0] == glm_mat_copy[2][0]);
      REQUIRE(my_mat_copy[2][1] == glm_mat_copy[2][1]);
      REQUIRE(my_mat_copy[2][2] == glm_mat_copy[2][2]);
    }
    {
      const Mat3 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[0][2] == glm_mat[0][2]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
      REQUIRE(my_mat[1][2] == glm_mat[1][2]);
      REQUIRE(my_mat[2][0] == glm_mat[2][0]);
      REQUIRE(my_mat[2][1] == glm_mat[2][1]);
      REQUIRE(my_mat[2][2] == glm_mat[2][2]);
    }
  }

  SECTION("Mat3 operations") {
    {
      const Mat3 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const Mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const glm::mat3x3 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3x3 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const auto my_result = my_mat_1 * my_mat_2;
      const auto glm_result = glm_mat_1 * glm_mat_2;

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      } 
    }
    {
      const Mat3 my_mat_1(1);
      const Mat3 my_mat_2(1);

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_mat_1[i][j] == my_mat_2[i][j]);
        }
      }

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE_FALSE(my_mat_1[i][j] != my_mat_2[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1;
      const Mat3 my_mat_2;

       for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_mat_1[i][j] == my_mat_2[i][j]);
        }
      }

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE_FALSE(my_mat_1[i][j] != my_mat_2[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const Mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

       for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_mat_1[i][j] == my_mat_2[i][j]);
        }
      }

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE_FALSE(my_mat_1[i][j] != my_mat_2[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const Mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const glm::mat3 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const auto my_result = my_mat_1 + my_mat_2;
      const auto glm_result = glm_mat_1 + glm_mat_2;

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
           REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const Mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const glm::mat3 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const auto my_result = my_mat_1 - my_mat_2;
      const auto glm_result = glm_mat_1 - glm_mat_2;

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 + 46.6f;
      const auto glm_result = glm_mat_1 + 46.6f;

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 - 46.6f;
      const auto glm_result = glm_mat_1 - 46.6f;

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 * 46.6f;
      const auto glm_result = glm_mat_1 * 46.6f;

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 * Vec3(-0.5f, 200.2f, 1.f);
      const auto glm_result = glm_mat_1 * glm::vec3(-0.5f, 200.2f, 1.f);

      REQUIRE(my_result[0] == Approx(-462.96).epsilon(EPS));
      REQUIRE(my_result[1] == Approx(58.06).epsilon(EPS));
      REQUIRE(my_result[2] == Approx(340.9).epsilon(EPS));
    }
    {
      const Mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 / 46.6f;
      const auto glm_result = glm_mat_1 / 46.6f;

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
  }

  SECTION("Mat3 functions") {
    {
      const Mat3 my_mat = Mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2).GetTransponed();
      const glm::mat3 glm_mat = glm::transpose(glm::mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2));

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
    {
      const Mat3 my_mat(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const glm::mat3 glm_mat(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      for (int i = 0; i < LENGTH_VEC3; i++) {
        auto row = my_mat.GetRow(i);

        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(row[j] == glm_mat[i][j]);
        }
      }
    }
    {
       const Mat3 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
       const Mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
       const Mat3 my_mat_3(1, 2, 3, 4, -10.f, 944.4f, -5, -4, 3);

       REQUIRE(my_mat_1 == my_mat_2);
       REQUIRE(my_mat_1 != my_mat_3);
    }
    {
      float my_det =  Mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2).GetDeterminant();
      float glm_det = glm::determinant(glm::mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2));

      REQUIRE(my_det == glm_det);
    }
    {
      const Mat3 my_invertible_mat = Mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2).GetInvertible();
      const glm::mat3 glm_invertible_mat = glm::inverse(glm::mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2));

       for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
           REQUIRE(my_invertible_mat[i][j] == Approx(glm_invertible_mat[i][j]).epsilon(EPS));
        }
      }
    }
    {
      const Mat3 my_invertible_mat = Mat3(11.111, -2, 3, 4, 0.f, 0, -123, -2, -2).GetInvertible();
      const glm::mat3 glm_invertible_mat = glm::inverse(glm::mat3(11.111, -2, 3, 4, 0.f, 0, -123, -2, -2));

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
           REQUIRE(my_invertible_mat[i][j] == Approx(glm_invertible_mat[i][j]).epsilon(EPS));
        }
      } 
    }
    {
      const Mat3 my_result = Mat3::GetIdentityMatrix();
      const glm::mat3 glm_result(1.0f);

      for (int i = 0; i < LENGTH_VEC3; i++) {
        for (int j = 0; j < LENGTH_VEC3; j++) {
          REQUIRE(my_result[i][j] == Approx(glm_result[i][j]).epsilon(EPS));
        }
      } 
    }
  }
}


TEST_CASE("Class Mat4 testing", "[mat]") {
  SECTION("Mat4 constructors") {
    {
      const Mat4 my_mat(1);
      const glm::mat4 glm_mat(1);

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      } 
    }
    {
      const Mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      
      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      } 
    }
    {
      const Mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_copy(my_mat);

      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_copy(glm_mat);

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      } 
    }
    {
      const Mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      } 
    }
  }

  SECTION("Mat4 operations") {
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4x4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4x4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 * my_mat_2;
      const auto glm_result = glm_mat_1 * glm_mat_2;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      } 
    }
    {
      const Mat4 my_mat_1(1);
      const Mat4 my_mat_2(1);

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat_1[i][j] == my_mat_2[i][j]);
        }
      }

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE_FALSE(my_mat_1[i][j] != my_mat_2[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1;
      const Mat4 my_mat_2;

       for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat_1[i][j] == my_mat_2[i][j]);
        }
      }

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE_FALSE(my_mat_1[i][j] != my_mat_2[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

       for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat_1[i][j] == my_mat_2[i][j]);
        }
      }

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE_FALSE(my_mat_1[i][j] != my_mat_2[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 + my_mat_2;
      const auto glm_result = glm_mat_1 + glm_mat_2;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
           REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 - my_mat_2;
      const auto glm_result = glm_mat_1 - glm_mat_2;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
           REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 + 77.8f;
      const auto glm_result = glm_mat_1 + 77.8f;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
           REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
     }
    {
       const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
       const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
       const Mat4 my_mat_3(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, -4);

       REQUIRE(my_mat_1 == my_mat_2);
       REQUIRE(my_mat_1 != my_mat_3);
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 - 77.8f;
      const auto glm_result = glm_mat_1 - 77.8f;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
           REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 * 77.8f;
      const auto glm_result = glm_mat_1 * 77.8f;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
           REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 / 77.8f;
      const auto glm_result = glm_mat_1 / 77.8f;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
           REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const Mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 * Vec4(-1, -2, -3, -4.44f);
      const auto glm_result = glm::vec4(-1, -2, -3, -4.44f) * glm_mat_1;

      for (int i = 0; i < LENGTH_VEC4; i++) {
           REQUIRE(my_result[i] == glm_result[i]);
      }
    }
  }

  SECTION("Mat4 functions") {
    {
      const Mat4 my_mat = Mat4(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4).GetTransponed();
      const glm::mat4 glm_mat = glm::transpose(glm::mat4(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4));

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
    {
      const Mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4);

      for (int i = 0; i < LENGTH_VEC4; i++) {
        auto row = my_mat.GetRow(i);

        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(row[j] == glm_mat[i][j]);
        }
      }
    }
    {
      float my_det =  Mat4(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4).GetDeterminant();
      float glm_det = glm::determinant(glm::mat4(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4));

      REQUIRE(my_det == glm_det);
    }
    {
      const Mat4 my_invertible_mat = Mat4(1, 2, 3, 4, 10.f, 12, 14, 4, 3, 12, -10, -77, 10, 2, 3, 4).GetInvertible();
      const glm::mat4 glm_invertible_mat = glm::inverse(glm::mat4(1, 2, 3, 4, 10.f, 12, 14, 4, 3, 12, -10, -77, 10, 2, 3, 4));

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
           REQUIRE(my_invertible_mat[i][j] == Approx(glm_invertible_mat[i][j]).epsilon(EPS));
        }
      }
    }
    {
      const Mat4 my_result = Mat4::GetIdentityMatrix();
      const glm::mat4 glm_result(1.0f);

      for (int i = 0; i < LENGTH_VEC4; i++) {
        for (int j = 0; j < LENGTH_VEC4; j++) {
          REQUIRE(my_result[i][j] == Approx(glm_result[i][j]).epsilon(EPS));
        }
      } 
    }
    {
      Vec4 my_vec(0.33f, -10.0f, 111.1, -22.2f);
      Vec3 vec_to_translate(15, 18.7f, -10.3f);
      auto my_translated = Mat4::GetTranslated(vec_to_translate);
      auto my_result = my_translated * my_vec;

      glm::vec4 glm_vec(0.33f, -10.0f, 111.1, -22.2f);
      auto glm_translated = glm::translate(glm::mat4(1.f), glm::vec3(15, 18.7f, -10.3f));
      glm_vec = glm_translated * glm_vec;

      for (int i = 0; i < LENGTH_VEC4; i++) {
          REQUIRE(my_result[i] == Approx(glm_vec[i]).epsilon(EPS));
      } 
    }
    {
      Vec4 my_vec(-1.15f, -200.0f, 123.12f, 0);
      Vec3 vec_to_scale(89, -100, -100);
      auto my_scaled = Mat4::GetScaled(vec_to_scale);
      auto my_result = my_scaled * my_vec;

      glm::vec4 glm_vec(-1.15f, -200.0f, 123.12f, 0);
      auto glm_scaled = glm::scale(glm::mat4(1.f), glm::vec3(89, -100, -100));
      glm_vec = glm_scaled * glm_vec;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        REQUIRE(my_result[i] == Approx(glm_vec[i]).epsilon(EPS));
      }
    }
    {
      Vec4 my_vec(1.0f, 0.0f, 0.0f, 1.0f);

      Vec3 vec_to_rotate(0.0, 0.0, 1.0);
      auto my_rotated = Mat4::GetRotated(90.0f, vec_to_rotate);
      auto my_result = my_rotated * my_vec;

      glm::vec4 glm_result(1.0f, 0.0f, 0.0f, 1.0f);
      auto glm_rotated = glm::rotate(glm::mat4(1.f), 90.0f, glm::vec3(0.0, 0.0, 1.0));
      glm_result = glm_rotated * glm_result;

      for (int i = 0; i < LENGTH_VEC4; i++) {
        REQUIRE(my_result[i] == Approx(glm_result[i]).epsilon(EPS));
      }
    }
  }
}
