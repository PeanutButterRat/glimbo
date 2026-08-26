#include "math.h"

#include <numbers>

using namespace glimbo;

float glimbo::radians(const float degrees) { return degrees * std::numbers::pi_v<float> / 180; }

float glimbo::degrees(const float radians) { return radians * 180 / std::numbers::pi_v<float>; }

Matrix::Matrix(const float diagonal) : data() {
    for (int i = 0; i < 4; i++) {
        (*this)[i][i] = diagonal;
    }
}

Matrix Matrix::operator*(const Matrix &other) const {
    Matrix result;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[j][i] = row(i).dot(other.column(j));
        }
    }

    return result;
}

Vec4 Matrix::row(std::size_t row) const { return {(*this)[0][row], (*this)[1][row], (*this)[2][row], (*this)[3][row]}; }

Vec4 Matrix::column(std::size_t column) const { return {(*this)[column][0], (*this)[column][1], (*this)[column][2], (*this)[column][3]}; }

Matrix Matrix::translation(const Vec3 &translation) {
    Matrix result{1};

    result[3][0] = translation[0];
    result[3][1] = translation[1];
    result[3][2] = translation[2];

    return result;
}

Matrix Matrix::rotation(const float degrees, const Vec3 &vector) {
    Matrix result{1};
    return result;
}

Matrix Matrix::scale(const Vec3 &scale) {
    Matrix result{1};

    result[0][0] = scale[0];
    result[1][1] = scale[1];
    result[2][2] = scale[2];

    return result;
}

Matrix Matrix::look_at(const Vec3 &eye, const Vec3 &target, const Vec3 &up) {
    const Vec3 f = (target - eye).normalized();
    const Vec3 s = f.cross(up).normalized();
    const Vec3 u = s.cross(f);

    Matrix result{1};

    result[0][0] = s[0];
    result[1][0] = s[1];
    result[2][0] = s[2];

    result[0][1] = u[0];
    result[1][1] = u[1];
    result[2][1] = u[2];

    result[0][2] = -f[0];
    result[1][2] = -f[1];
    result[2][2] = -f[2];

    result[3][0] = -s.dot(eye);
    result[3][1] = -u.dot(eye);
    result[3][2] = f.dot(eye);

    return result;
}

Matrix Matrix::perspective(float fov, float aspect, float near, float far) {
    Matrix result;

    const float tan_half_fov = std::tan(radians(fov) / 2.0f);

    result[0][0] = 1.0f / (aspect * tan_half_fov);
    result[1][1] = 1.0f / tan_half_fov;

    result[2][2] = -(far + near) / (far - near);
    result[3][2] = -(2.0f * far * near) / (far - near);

    result[2][3] = -1.0f;

    return result;
}

const float *Matrix::buffer() const { return data.data(); }
