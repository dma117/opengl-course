#include "math.h"

#include <cmath>

Vec2::Vec2() : x_(0), y_(0) {}

Vec2::Vec2(float coord) : x_(coord), y_(coord) {}

Vec2::Vec2(float x, float y) : x_(x), y_(y) {}

Vec2::Vec2(const Vec2& other) {
  this->x_ = other.x_;
  this->y_ = other.y_;
}

Vec2 Vec2::operator+(const Vec2& other) const {
  return {this->x_ + other.x_, this->y_ + other.y_};
}

Vec2 Vec2::operator-(const Vec2& other) const {
  return {this->x_ - other.x_, this->y_ - other.y_};
}

float Vec2::GetScalarProductWith(const Vec2& other) const {
  return this->x_ * other.x_ + this->y_ * other.y_;
}

Vec2 Vec2::operator*(float num) const {
  return {this->x_ * num, this->y_ * num};
}

Vec2 Vec2::operator/(float num) const {
  return {this->x_ / num, this->y_ / num};
}

float Vec2::operator[](int coord) const {
  if (coord < 0 || coord >= LENGTH_VEC2) {
  }  // TODO maybe throw exception

  switch (coord) {
    case 0:
      return x_;
    case 1:
      return y_;
  }
}

Vec2& Vec2::operator+=(const Vec2& other) {
  this->x_ += other.x_;
  this->y_ += other.y_;

  return *this;
}

Vec2& Vec2::operator-=(const Vec2& other) {
  this->x_ -= other.x_;
  this->y_ -= other.y_;

  return *this;
}

Vec2& Vec2::operator*=(float num) {
  this->x_ *= num;
  this->y_ *= num;

  return *this;
}

Vec2& Vec2::operator/=(float num) {
  this->x_ /= num;
  this->y_ /= num;

  return *this;
}

float& Vec2::operator[](int coord) {
  switch (coord) {
    case 0:
      return x_;
    case 1:
      return y_;
  }
}

bool Vec2::operator==(const Vec2& other) const {
  return this->x_ == other.x_ && this->y_ == other.y_;
}

bool Vec2::operator!=(const Vec2& other) const { return !(*this == other); }

double Vec2::Length() const { return sqrt(pow(x_, 2) + pow(y_, 2)); }

Vec2 Vec2::Normalize() const {
  auto inv_length = 1 / this->Length();

  return {*this * inv_length};
}

Vec3::Vec3() : x_(0), y_(0), z_(0) {}

Vec3::Vec3(float coord) : x_(coord), y_(coord), z_(coord) {}

Vec3::Vec3(float x, float y, float z) : x_(x), y_(y), z_(z) {}

Vec3::Vec3(const Vec3& other) {
  this->x_ = other.x_;
  this->y_ = other.y_;
  this->z_ = other.z_;
}

Vec3 Vec3::operator+(const Vec3& other) const {
  return {this->x_ + other.x_, this->y_ + other.y_, this->z_ + other.z_};
}

Vec3 Vec3::operator-(const Vec3& other) const {
  return {this->x_ - other.x_, this->y_ - other.y_, this->z_ - other.z_};
}

float Vec3::GetScalarProductWith(const Vec3& other) const {
  return this->x_ * other.x_ + this->y_ * other.y_ + this->z_ * other.z_;
}

Vec3 Vec3::GetVectorProductWith(const Vec3& other) const {
  auto coord_x = this->y_ * other.z_ - other.y_ * this->z_;
  auto coord_y = -(this->x_ * other.z_ - other.x_ * this->z_);
  auto coord_z = this->x_ * other.y_ - other.x_ * this->y_;

  return {coord_x, coord_y, coord_z};
}

Vec3 Vec3::operator*(float num) const {
  return {this->x_ * num, this->y_ * num, this->z_ * num};
}

Vec3 Vec3::operator/(float num) const {
  return {this->x_ / num, this->y_ / num, this->z_ / num};
}

float Vec3::operator[](int coord) const {
  switch (coord) {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
  }
}

Vec3& Vec3::operator+=(const Vec3& other) {
  this->x_ += other.x_;
  this->y_ += other.y_;
  this->z_ += other.z_;

  return *this;
}

Vec3& Vec3::operator-=(const Vec3& other) {
  this->x_ -= other.x_;
  this->y_ -= other.y_;
  this->z_ -= other.z_;

  return *this;
}

Vec3& Vec3::operator*=(float num) {
  this->x_ *= num;
  this->y_ *= num;
  this->z_ *= num;

  return *this;
}

Vec3& Vec3::operator/=(float num) {
  this->x_ /= num;
  this->y_ /= num;
  this->z_ /= num;

  return *this;
}

float& Vec3::operator[](int coord) {
  switch (coord) {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
  }
}

bool Vec3::operator==(const Vec3& other) const {
  return this->x_ == other.x_ && this->y_ == other.y_ && this->z_ == other.z_;
}

bool Vec3::operator!=(const Vec3& other) const { return !(*this == other); }

double Vec3::Length() const {
  return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

Vec3 Vec3::Normalize() const { return {*this / this->Length()}; }

Vec4::Vec4() : x_(0), y_(0), z_(0), w_(0) {}

Vec4::Vec4(float coord) : x_(coord), y_(coord), z_(coord), w_(coord) {}

Vec4::Vec4(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) {}

Vec4::Vec4(const Vec4& other) {
  this->x_ = other.x_;
  this->y_ = other.y_;
  this->z_ = other.z_;
  this->w_ = other.w_;
}

Vec4 Vec4::operator+(const Vec4& other) const {
  return {this->x_ + other.x_, this->y_ + other.y_, this->z_ + other.z_,
          this->w_ + other.w_};
}

Vec4 Vec4::operator-(const Vec4& other) const {
  return {this->x_ - other.x_, this->y_ - other.y_, this->z_ - other.z_,
          this->w_ - other.w_};
}

float Vec4::GetScalarProductWith(const Vec4& other) const {
  auto x = this->x_ * other.x_;
  auto y = this->y_ * other.y_;
  auto z = this->z_ * other.z_;
  auto w = this->w_ * other.w_;

  // return this->x_ * other.x_ + this->y_ * other.y_ + this->z_ * other.z_ +
  // this->w_ + other.w_;
  return x + y + z + w;
}

Vec4 Vec4::operator*(float num) const {
  return {this->x_ * num, this->y_ * num, this->z_ * num, this->w_ * num};
}

Vec4 Vec4::operator/(float num) const {
  return {this->x_ / num, this->y_ / num, this->z_ / num, this->w_ / num};
}

float Vec4::operator[](int coord) const {
  switch (coord) {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
    case 3:
      return w_;
  }
}

Vec4& Vec4::operator+=(const Vec4& other) {
  this->x_ += other.x_;
  this->y_ += other.y_;
  this->z_ += other.z_;
  this->w_ += other.w_;

  return *this;
}

Vec4& Vec4::operator-=(const Vec4& other) {
  this->x_ -= other.x_;
  this->y_ -= other.y_;
  this->z_ -= other.z_;
  this->w_ -= other.w_;

  return *this;
}

Vec4& Vec4::operator*=(float num) {
  this->x_ *= num;
  this->y_ *= num;
  this->z_ *= num;
  this->w_ *= num;

  return *this;
}

Vec4& Vec4::operator/=(float num) {
  this->x_ /= num;
  this->y_ /= num;
  this->z_ /= num;
  this->w_ /= num;

  return *this;
}

float& Vec4::operator[](int coord) {
  switch (coord) {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
    case 3:
      return w_;
  }
}

bool Vec4::operator==(const Vec4& other) const {
  return this->x_ == other.x_ && this->y_ == other.y_ && this->z_ == other.z_ &&
         this->w_ == other.w_;
}

bool Vec4::operator!=(const Vec4& other) const { return !(*this == other); }

double Vec4::Length() const {
  return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2) + pow(w_, 2));
}

Vec4 Vec4::Normalize() const {
  auto inv_length = 1 / this->Length();

  return {*this * inv_length};
}

Mat2::Mat2() { matrix_ = std::vector<Vec2>(2, 0); }

Mat2::Mat2(float coord) {
  for (int i = 0; i < LENGTH_VEC2; i++) {
    Vec2 vector(0);
    vector[i] = coord;
    matrix_.push_back(vector);
  }
}

Mat2::Mat2(float x1, float y1, float x2, float y2) {
  matrix_.push_back({x1, y1});
  matrix_.push_back({x2, y2});
}

Mat2::Mat2(const Mat2& other) {
  this->matrix_.clear();

  for (int i = 0; i < LENGTH_VEC2; i++) {
    matrix_.push_back(other.matrix_[i]);
  }
}

Mat2 Mat2::operator+(const Mat2& other) const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result.matrix_[i] = this->matrix_[i] + other.matrix_[i];
  }

  return result;
}

Mat2 Mat2::operator+(float num) const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result.matrix_[i] = this->matrix_[i] + num;
  }

  return result;
}

Mat2 Mat2::operator-(const Mat2& other) const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result.matrix_[i] = this->matrix_[i] - other.matrix_[i];
  }

  return result;
}

Mat2 Mat2::operator-(float num) const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result.matrix_[i] = this->matrix_[i] - num;
  }

  return result;
}

Mat2 Mat2::operator*(const Mat2& other) const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    Vec2 vector;

    for (int j = 0; j < LENGTH_VEC2; j++) {
      for (int k = 0; k < LENGTH_VEC2; k++) {
        vector[j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }

    result.matrix_[i] = vector;
  }

  return result;
}

Vec2 Mat2::operator*(const Vec2& vector) const {
  Vec2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    for (int j = 0; j < LENGTH_VEC1; j++) {
      Vec2 row = GetRow(i);
      result[i] = row.GetScalarProductWith(vector);
    }
  }

  return result;
}

Mat2 Mat2::operator*(float num) const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result.matrix_[i] = matrix_[i] * num;
  }

  return result;
}

Mat2 Mat2::operator/(float num) const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result.matrix_[i] = matrix_[i] / num;
  }

  return result;
}

Vec2 Mat2::operator[](int index) const {
  // TODO check index out of range
  return GetRow(index);
}

bool Mat2::operator==(const Mat2& other) const {
  for (int i = 0; i < LENGTH_VEC2; i++) {
    if (this->matrix_[i] != other.matrix_[i]) {
      return false;
    }
  }

  return true;
}

bool Mat2::operator!=(const Mat2& other) const { return !(*this == other); }

Vec2 Mat2::GetRow(int index) const {
  // check index
  return matrix_[index];
}

Vec2 Mat2::GetCol(int index) const {
  // check index TODO
  Vec2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result[i] = matrix_[i][index];
  }

  return result;
}

float Mat2::GetDeterminant() const {
  return {matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1]};
}

Mat2 Mat2::GetTransponed() const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    result.matrix_[i] = GetCol(i);
  }

  return result;
}

Mat2 Mat2::GetInvertible() const {
  return {GetTransponed().GetMat2OfAlgebraicComplements() / GetDeterminant()};
}

float Mat2::GetMinor(int row, int col) const {
  float result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    for (int j = 0; j < LENGTH_VEC2; j++) {
      if (i == row || j == col) {
        continue;
      }

      result = matrix_[i][j];
    }
  }

  return result;
}

float Mat2::GetAlgebraicComplement(int row, int col) const {
  int factor = 1;

  if ((row + col) % 2 == 1) {
    factor = -1;
  }

  return factor * GetMinor(row, col);
}

Mat2 Mat2::GetMat2OfAlgebraicComplements() const {
  Mat2 result;

  for (int i = 0; i < LENGTH_VEC2; i++) {
    for (int j = 0; j < LENGTH_VEC2; j++) {
      result.matrix_[i][j] = GetAlgebraicComplement(i, j);
    }
  }

  return result;
}

Mat2 Mat2::GetIdentityMatrix() { return {1}; }

Mat3::Mat3() { matrix_ = std::vector<Vec3>(3, 0); }

Mat3::Mat3(float coord) {
  for (int i = 0; i < LENGTH_VEC3; i++) {
    Vec3 vector(0);
    vector[i] = coord;
    matrix_.push_back(vector);
  }
}

Mat3::Mat3(float x1, float y1, float z1, float x2, float y2, float z2, float x3,
           float y3, float z3) {
  matrix_.push_back({x1, y1, z1});
  matrix_.push_back({x2, y2, z2});
  matrix_.push_back({x3, y3, z3});
}

Mat3::Mat3(const Mat3& other) {
  this->matrix_.clear();

  for (int i = 0; i < LENGTH_VEC3; i++) {
    matrix_.push_back(other.matrix_[i]);
  }
}

Mat3 Mat3::operator+(const Mat3& other) const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result.matrix_[i] = this->matrix_[i] + other.matrix_[i];
  }

  return result;
}

Mat3 Mat3::operator+(float num) const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result.matrix_[i] = this->matrix_[i] + num;
  }

  return result;
}

Mat3 Mat3::operator-(const Mat3& other) const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result.matrix_[i] = this->matrix_[i] - other.matrix_[i];
  }

  return result;
}

Mat3 Mat3::operator-(float num) const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result.matrix_[i] = this->matrix_[i] - num;
  }

  return result;
}

Mat3 Mat3::operator*(const Mat3& other) const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    Vec3 vector;

    for (int j = 0; j < LENGTH_VEC3; j++) {
      for (int k = 0; k < LENGTH_VEC3; k++) {
        vector[j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }

    result.matrix_[i] = vector;
  }

  return result;
}

Vec3 Mat3::operator*(const Vec3& vector) const {
  Vec3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    for (int j = 0; j < LENGTH_VEC1; j++) {
      Vec3 row = GetRow(i);
      result[i] = row.GetScalarProductWith(vector);
    }
  }

  return result;
}

Mat3 Mat3::operator*(float num) const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result.matrix_[i] = this->matrix_[i] * num;
  }

  return result;
}

Mat3 Mat3::operator/(float num) const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result.matrix_[i] = this->matrix_[i] / num;
  }

  return result;
}

Vec3 Mat3::operator[](int index) const { return GetRow(index); }

bool Mat3::operator==(const Mat3& other) const {
  for (int i = 0; i < LENGTH_VEC3; i++) {
    if (this->matrix_[i] != other.matrix_[i]) {
      return false;
    }
  }

  return true;
}

bool Mat3::operator!=(const Mat3& other) const { return !(*this == other); }

Vec3 Mat3::GetRow(int index) const { return matrix_[index]; }

Vec3 Mat3::GetCol(int index) const {
  // check index TODO
  Vec3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result[i] = matrix_[i][index];
  }

  return result;
}

float Mat3::GetDeterminant() const {
  float result = 0;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result += matrix_[0][i] * GetAlgebraicComplement(0, i);
  }
  return result;
}

Mat3 Mat3::GetTransponed() const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    result.matrix_[i] = GetCol(i);
  }

  return result;
}

Mat3 Mat3::GetInvertible() const {
  return {GetTransponed().GetMat3OfAlgebraicComplements() / GetDeterminant()};
}

float Mat3::GetMinor(int row, int col) const {
  std::vector<float> values;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    for (int j = 0; j < LENGTH_VEC3; j++) {
      if (i == row || j == col) {
        continue;
      }

      values.emplace_back(matrix_[i][j]);
    }
  }

  return Mat2(values[0], values[1], values[2], values[3]).GetDeterminant();
}

float Mat3::GetAlgebraicComplement(int row, int col) const {
  int factor = 1;

  if ((row + col) % 2 == 1) {
    factor = -1;
  }

  return factor * GetMinor(row, col);
}

Mat3 Mat3::GetMat3OfAlgebraicComplements() const {
  Mat3 result;

  for (int i = 0; i < LENGTH_VEC3; i++) {
    for (int j = 0; j < LENGTH_VEC3; j++) {
      result.matrix_[i][j] = GetAlgebraicComplement(i, j);
    }
  }

  return result;
}

Mat3 Mat3::GetIdentityMatrix() { return {1}; }

Mat4::Mat4() { matrix_ = std::vector<Vec4>(4, 0); }

Mat4::Mat4(float coord) {
  for (int i = 0; i < LENGTH_VEC4; i++) {
    Vec4 vector(0);
    vector[i] = coord;
    matrix_.push_back(vector);
  }
}

Mat4::Mat4(float x1, float y1, float z1, float w1, float x2, float y2, float z2,
           float w2, float x3, float y3, float z3, float w3, float x4, float y4,
           float z4, float w4) {
  matrix_.push_back({x1, y1, z1, w1});
  matrix_.push_back({x2, y2, z2, w2});
  matrix_.push_back({x3, y3, z3, w3});
  matrix_.push_back({x4, y4, z4, w4});
}

Mat4::Mat4(const Mat4& other) {
  this->matrix_.clear();

  for (int i = 0; i < LENGTH_VEC4; i++) {
    matrix_.push_back(other.matrix_[i]);
  }
}

Mat4 Mat4::operator+(const Mat4& other) const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result.matrix_[i] = this->matrix_[i] + other.matrix_[i];
  }

  return result;
}

Mat4 Mat4::operator+(float num) const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result.matrix_[i] = this->matrix_[i] + num;
  }

  return result;
}

Mat4 Mat4::operator-(const Mat4& other) const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result.matrix_[i] = this->matrix_[i] - other.matrix_[i];
  }

  return result;
}

Mat4 Mat4::operator-(float num) const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result.matrix_[i] = this->matrix_[i] - num;
  }

  return result;
}

Mat4 Mat4::operator*(const Mat4& other) const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    Vec4 vector;

    for (int j = 0; j < LENGTH_VEC4; j++) {
      for (int k = 0; k < LENGTH_VEC4; k++) {
        vector[j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }

    result.matrix_[i] = vector;
  }

  return result;
}

Vec4 Mat4::operator*(const Vec4& vector) const {
  Vec4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    for (int j = 0; j < LENGTH_VEC1; j++) {
      Vec4 row = GetRow(i);
      result[i] = row.GetScalarProductWith(vector);
    }
  }

  return result;
}

Mat4 Mat4::operator*(float num) const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result.matrix_[i] = this->matrix_[i] * num;
  }

  return result;
}

Mat4 Mat4::operator/(float num) const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result.matrix_[i] = this->matrix_[i] / num;
  }

  return result;
}

Vec4 Mat4::operator[](int index) const { return GetRow(index); }

Vec4& Mat4::operator[](int index) { return matrix_[index]; }

bool Mat4::operator==(const Mat4& other) const {
  for (int i = 0; i < LENGTH_VEC4; i++) {
    if (this->matrix_[i] != other.matrix_[i]) {
      return false;
    }
  }

  return true;
}

bool Mat4::operator!=(const Mat4& other) const { return !(*this == other); }

Vec4 Mat4::GetRow(int index) const { return matrix_[index]; }

Vec4 Mat4::GetCol(int index) const {
  // check index TODO
  Vec4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result[i] = matrix_[i][index];
  }

  return result;
}

float Mat4::GetDeterminant() const {
  float result = 0;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result += matrix_[0][i] * GetAlgebraicComplement(0, i);
  }
  return result;
}

Mat4 Mat4::GetTransponed() const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    result.matrix_[i] = GetCol(i);
  }

  return result;
}

Mat4 Mat4::GetInvertible() const {
  return {GetTransponed().GetMat4OfAlgebraicComplements() / GetDeterminant()};
}

Mat4 Mat4::GetTranslated(const Vec3& vector) {
  Mat4 result = Mat4::GetIdentityMatrix();

  result.matrix_[0][3] = vector[0];
  result.matrix_[1][3] = vector[1];
  result.matrix_[2][3] = vector[2];

  return result;
}

Mat4 Mat4::GetScaled(const Vec3& vector) {
  Mat4 result = Mat4::GetIdentityMatrix();

  result.matrix_[0][0] = vector[0];
  result.matrix_[1][1] = vector[1];
  result.matrix_[2][2] = vector[2];

  return result;
}

Mat4 Mat4::GetRotated(float angle, const Vec3& vector) {
  auto param = 1 - cos(angle);

  float x = vector[0];
  float y = vector[1];
  float z = vector[2];

  Mat4 rotate_matrix;

  rotate_matrix[0][0] = cos(angle) + param * pow(x, 2);
  rotate_matrix[0][1] = param * x * y - sin(angle) * z;
  rotate_matrix[0][2] = param * x * z + sin(angle) * y;

  rotate_matrix[1][0] = param * y * x + sin(angle) * z;
  rotate_matrix[1][1] = cos(angle) + param * pow(y, 2);
  rotate_matrix[1][2] = param * y * z - sin(angle) * x;

  rotate_matrix[2][0] = param * z * x - sin(angle) * y;
  rotate_matrix[2][1] = param * z * y + sin(angle) * x;
  rotate_matrix[2][2] = cos(angle) + param * pow(z, 2);

  rotate_matrix[3][3] = 1;

  return rotate_matrix;
}

float Mat4::GetMinor(int row, int col) const {
  std::vector<float> values;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    for (int j = 0; j < LENGTH_VEC4; j++) {
      if (i == row || j == col) {
        continue;
      }

      values.emplace_back(matrix_[i][j]);
    }
  }

  return Mat3(values[0], values[1], values[2], values[3], values[4], values[5],
              values[6], values[7], values[8])
      .GetDeterminant();
}

float Mat4::GetAlgebraicComplement(int row, int col) const {
  int factor = 1;

  if ((row + col) % 2 == 1) {
    factor = -1;
  }

  return factor * GetMinor(row, col);
}

Mat4 Mat4::GetMat4OfAlgebraicComplements() const {
  Mat4 result;

  for (int i = 0; i < LENGTH_VEC4; i++) {
    for (int j = 0; j < LENGTH_VEC4; j++) {
      result.matrix_[i][j] = GetAlgebraicComplement(i, j);
    }
  }

  return result;
}

Mat4 Mat4::Perspective(float fov, float ratio, float near, float far) { 
  float tan_fov = tan(fov / 2.0f);

  Mat4 result(0.0f);
  result.matrix_[0][0] = 1.0f / (ratio * tan_fov);
  result.matrix_[1][1] = 1.0f / (tan_fov);
  result.matrix_[2][2] = -(far + near) / (far - near);
  result.matrix_[2][3] = -1.0f;
  result.matrix_[3][2] = -(2.0f * far * near) / (far - near);

  return result;
}

Mat4 Mat4::GetIdentityMatrix() { return {1.0f}; }
 
Mat4 Mat4::LookAt(Vec3 position, Vec3 center, Vec3 up) {
    Vec3 vec_one(position - center);
    Vec3 z_axis(vec_one.Normalize());

    Vec3 vec_up(up.Normalize());
    Vec3 vector_product(vec_up.GetVectorProductWith(z_axis));
    Vec3 x_axis(vector_product.Normalize());

    Vec3 y_axis(z_axis.GetVectorProductWith(x_axis));

    Mat4 rotation(1.0f);
    rotation.matrix_[0][0] = x_axis[0];
    rotation.matrix_[1][0] = x_axis[1];
    rotation.matrix_[2][0] = x_axis[2];
    rotation.matrix_[0][1] = y_axis[0];
    rotation.matrix_[1][1] = y_axis[1];
    rotation.matrix_[2][1] = y_axis[2];
    rotation.matrix_[0][2] = z_axis[0];
    rotation.matrix_[1][2] = z_axis[1];
    rotation.matrix_[2][2] = z_axis[2];

    Mat4 translation(1.0f);
    translation.matrix_[3][0] = -position[0];
    translation.matrix_[3][1] = -position[1];
    translation.matrix_[3][2] = -position[2];

    return translation * rotation;
}
