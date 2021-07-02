#pragma once
#include <vector>

const int LENGTH_VEC1 = 1;
const int LENGTH_VEC2 = 2;
const int LENGTH_VEC3 = 3;
const int LENGTH_VEC4 = 4;

class Vec2 {
 public:
  Vec2();
  Vec2(float);
  Vec2(float, float);
  Vec2(const Vec2&);

  Vec2 operator+(const Vec2&) const;
  Vec2 operator-(const Vec2&) const;
  float GetScalarProductWith(const Vec2&) const;
  Vec2 operator*(float) const;
  Vec2 operator/(float) const;
  float operator[](int) const;

  Vec2& operator+=(const Vec2&);
  Vec2& operator-=(const Vec2&);
  Vec2& operator*=(float);
  Vec2& operator/=(float);
  float& operator[](int);

  bool operator==(const Vec2&) const;
  bool operator!=(const Vec2&) const;

  double Length() const;
  Vec2 Normalize() const;

 private:
  float x_;
  float y_;
};

class Vec3 {
 public:
  Vec3();
  Vec3(float);
  Vec3(float, float, float);
  Vec3(const Vec3&);

  Vec3 operator+(const Vec3&) const;
  Vec3 operator-(const Vec3&) const;
  float GetScalarProductWith(const Vec3&) const;
  Vec3 GetVectorProductWith(const Vec3&) const;
  Vec3 operator*(float) const;
  Vec3 operator/(float) const;
  float operator[](int) const;

  Vec3& operator+=(const Vec3&);
  Vec3& operator-=(const Vec3&);
  Vec3& operator*=(float);
  Vec3& operator/=(float);
  float& operator[](int);

  bool operator==(const Vec3&) const;
  bool operator!=(const Vec3&) const;

  double Length() const;
  Vec3 Normalize() const;

 private:
  float x_;
  float y_;
  float z_;
};

class Vec4 {
 public:
  Vec4();
  Vec4(float);
  Vec4(float, float, float, float);
  Vec4(const Vec4&);

  Vec4 operator+(const Vec4&) const;
  Vec4 operator-(const Vec4&) const;
  float GetScalarProductWith(const Vec4&) const;
  Vec4 operator*(float) const;
  Vec4 operator/(float) const;
  float operator[](int) const;

  Vec4& operator+=(const Vec4&);
  Vec4& operator-=(const Vec4&);
  Vec4& operator*=(float);
  Vec4& operator/=(float);
  float& operator[](int);

  bool operator==(const Vec4&) const;
  bool operator!=(const Vec4&) const;

  double Length() const;
  Vec4 Normalize() const;

 private:
  float x_;
  float y_;
  float z_;
  float w_;
};

class Mat2 {
 public:
  Mat2();
  Mat2(float);
  Mat2(float, float, float, float);
  Mat2(const Mat2&);

  Mat2 operator+(const Mat2&) const;
  Mat2 operator+(float) const;
  Mat2 operator-(const Mat2&) const;
  Mat2 operator-(float) const;
  Mat2 operator*(const Mat2&) const;
  Vec2 operator*(const Vec2&) const;
  Mat2 operator*(float) const;
  Mat2 operator/(float) const;
  Vec2 operator[](int) const;
  bool operator==(const Mat2&) const;
  bool operator!=(const Mat2&) const;

  Vec2 GetRow(int) const;
  Vec2 GetCol(int) const;

  float GetDeterminant() const;

  Mat2 GetTransponed() const;
  Mat2 GetInvertible() const;
  float GetMinor(int, int) const;
  float GetAlgebraicComplement(int, int) const;
  Mat2 GetMat2OfAlgebraicComplements() const;

  static Mat2 GetIdentityMatrix();

 private:
  std::vector<Vec2> matrix_;
};

class Mat3 {
 public:
  Mat3();
  Mat3(float);
  Mat3(float, float, float, float, float, float, float, float, float);
  Mat3(const Mat3&);

  Mat3 operator+(const Mat3&) const;
  Mat3 operator+(float) const;
  Mat3 operator-(const Mat3&) const;
  Mat3 operator-(float) const;
  Mat3 operator*(const Mat3&) const;
  Vec3 operator*(const Vec3&) const;
  Mat3 operator*(float) const;
  Mat3 operator/(float) const;
  Vec3 operator[](int) const;
  bool operator==(const Mat3&) const;
  bool operator!=(const Mat3&) const;

  Vec3 GetRow(int) const;
  Vec3 GetCol(int) const;

  float GetDeterminant() const;

  Mat3 GetTransponed() const;
  Mat3 GetInvertible() const;
  float GetMinor(int, int) const;
  float GetAlgebraicComplement(int, int) const;
  Mat3 GetMat3OfAlgebraicComplements() const;

  static Mat3 GetIdentityMatrix();

 private:
  std::vector<Vec3> matrix_;
};

class Mat4 {
 public:
  Mat4();
  Mat4(float);
  Mat4(float, float, float, float, float, float, float, float, float, float,
       float, float, float, float, float, float);
  Mat4(const Mat4&);

  Mat4 operator+(const Mat4&) const;
  Mat4 operator+(float) const;
  Mat4 operator-(const Mat4&) const;
  Mat4 operator-(float) const;
  Mat4 operator*(const Mat4&) const;
  Vec4 operator*(const Vec4&) const;
  Mat4 operator*(float) const;
  Mat4 operator/(float) const;
  Vec4 operator[](int) const;
  Vec4& operator[](int);
  bool operator==(const Mat4&) const;
  bool operator!=(const Mat4&) const;

  Vec4 GetRow(int) const;
  Vec4 GetCol(int) const;

  float GetDeterminant() const;

  Mat4 GetTransponed() const;
  Mat4 GetInvertible() const;
  static Mat4 GetTranslated(const Vec3&);
  static Mat4 GetScaled(const Vec3&);
  static Mat4 GetRotated(float, const Vec3&);
  float GetMinor(int, int) const;
  float GetAlgebraicComplement(int, int) const;
  Mat4 GetMat4OfAlgebraicComplements() const;
  
  static Mat4 Perspective(float, float, float, float);
  static Mat4 GetIdentityMatrix();
  static Mat4 LookAt(Vec3, Vec3, Vec3);

 private:
  std::vector<Vec4> matrix_;
};
