#pragma once

#include <array>
#include <cmath>
#include <functional>

namespace glimbo {
    float radians(float degrees);
    float degrees(float radians);

    template<std::size_t N>
    struct Vec {
        Vec() = default;

        template<typename... Args>
            requires(sizeof...(Args) == N)
        Vec(Args... args) : data{static_cast<float>(args)...} {}

        Vec(const float *values) {
            for (std::size_t i = 0; i < N; ++i) {
                data[i] = values[i];
            }
        }

        float &operator[](std::size_t i) { return data[i]; }

        const float &operator[](std::size_t i) const { return data[i]; }

        Vec operator+(const Vec &other) const { return combine(std::plus(), other); }

        Vec operator-(const Vec &other) const { return combine(std::minus(), other); }

        Vec operator*(float scalar) const {
            return map([scalar](const float x) { return x * scalar; });
        }

        Vec operator/(float scalar) const {
            return map([scalar](const float x) { return x / scalar; });
        }

        float dot(const Vec &other) const { return combine(std::multiplies(), other).reduce(std::plus()); }

        float length() const { return std::sqrt(dot(*this)); }

        Vec normalized() const { return *this / length(); }

        Vec cross(const Vec &other) const
            requires(N == 3)
        {
            return {data[1] * other[2] - data[2] * other[1], data[2] * other[0] - data[0] * other[2], data[0] * other[1] - data[1] * other[0]};
        }

    private:
        std::array<float, N> data;

        float reduce(const std::function<float(float, float)> &function, float accumulator = 0) const {
            for (size_t i = 0; i < N; ++i) {
                accumulator = function(accumulator, data[i]);
            }

            return accumulator;
        }

        Vec map(const std::function<float(float)> &function) const {
            Vec result;

            for (std::size_t i = 0; i < N; ++i) {
                result[i] = function(data[i]);
            }

            return result;
        }

        Vec combine(const std::function<float(float, float)> &function, const Vec &other) const {
            Vec result;

            for (std::size_t i = 0; i < N; ++i) {
                result[i] = function(data[i], other[i]);
            }

            return result;
        }
    };

    using Vec2 = Vec<2>;
    using Vec3 = Vec<3>;
    using Vec4 = Vec<4>;

    struct Matrix {
        Matrix(float diagonal = 0);

        Matrix operator*(const Matrix &other) const;

        float *operator[](const std::size_t column) { return &data[column * 4]; }

        const float *operator[](const std::size_t column) const { return &data[column * 4]; }

        Vec4 row(size_t row) const;

        Vec4 column(size_t column) const;

        static Matrix translation(const Vec3 &translation);

        static Matrix rotation(float degrees, const Vec3 &vector);

        static Matrix scale(const Vec3 &scale);

        static Matrix look_at(const Vec3 &eye, const Vec3 &target, const Vec3 &up);

        static Matrix perspective(float fov, float aspect, float near, float far);

        const float *buffer() const;

    private:
        std::array<float, 16> data;
    };

}; // namespace glimbo
