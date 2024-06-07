#pragma once

#include <string>
#include <vector>
#include <array>
#include <stdexcept>
#include <cmath>

#include <iostream>

namespace VecLib {
	namespace {
		const double pi = 3.14159265358979323846;

		template<class T, size_t Sn>
		class Vec {
		public:
			Vec() {
				vec = std::vector<float>(Sn, .0f);
			}
			Vec(float x) : Vec() {
				vec[0] = x;
			}
			Vec(float x, float y) {
				vec[0] = x;
				vec[1] = y;
			}
			Vec(float x, float y, float z) {
				vec[0] = x;
				vec[1] = y;
				vec[2] = z;
			}
			Vec(float x, float y, float z, float w) {
				vec[0] = x;
				vec[1] = y;
				vec[2] = z;
				vec[3] = w;
			}

			std::string to_string() const {
				std::string res = "[";
				size_t i = 0;
				for (const auto & n : vec) {
					res += std::to_string(n);
					if (i++ != vec.size() - 1) { res += ";"; }
				}
				res += "]";
				return res;
			}

			double magnitude() const {
				double res = .0f;
				for (const auto& n : vec) {
					res += pow(n, 2);
				}
				return sqrt(res);
			}

			double dot(const T& in) {
				double res = .0f;
				size_t i = 0;
				for (const auto & n : vec) {
					res += n * in[i++];
				}
				return res;
			}

			double anglerad(const T& in) const {
				double res = acos(this->dot(in) / (this->magnitude() * in.magnitude()));
				if (res > pi)	{ return res - pi; } 
				else			{ return res; }
			}

			double angledeg(const T& in) const {
				return this->anglerad(in) * 180.f / pi;
			}

			void normalize() {
				double m = this->magnitude();
				for (auto& n : vec) {
					n /= m;
				}
			}

			std::vector<float> as_vector() {
				return vec;
			}

			template<class ...Ts>
			T cross(Ts &&...in) {
				T res = T();

				std::vector<std::vector<float>> mat;
				(insert(mat, in), ...);

				for (size_t row = 0; row < Sn; row++) {
					for (size_t i = 0; i < Sn; i++) {

					}
				}
			}

		protected:
			std::vector<float> vec;

			void insert(std::vector<std::vector<float>>& mat, const T& in) {
				mat.push_back(in.vec);

			// testing only
				std::cout << in.to_string();
			}
		};

		template<class T>
		class Mat {
		public:

		};
	}

	class Vec3 : protected Vec<Vec3, 3> {
	public:
		Vec3() : Vec() {};
		Vec3(float x) : Vec(x) {};
		Vec3(float x, float y) : Vec(x, y) {};
		Vec3(float x, float y, float z) : Vec(x, y, z) {};
		Vec3(const Vec3& in) {
			*this = in;
		};

		float& operator[](size_t idx);
		const float& operator[](size_t idx) const;
		Vec3& operator=(const Vec3& rhs);
		Vec3& operator+=(const Vec3& rhs);
		Vec3& operator-=(const Vec3& rhs);
		Vec3 operator+(const Vec3& rhs);
		Vec3 operator-(const Vec3& rhs);
		template<typename Tn>
		Vec3 operator/(const Tn& rhs);
		template<typename Tn>
		Vec3 operator*(const Tn& rhs);
		template<typename Tn>
		Vec3& operator/=(const Tn& rhs);
		template<typename Tn>
		Vec3& operator*=(const Tn& rhs);
	};
	

	class Vec4 : protected Vec<Vec4, 4> {
	public:
		Vec4() : Vec() {};
		Vec4(float x) : Vec(x) {};
		Vec4(float x, float y) : Vec(x, y) {};
		Vec4(float x, float y, float z) : Vec(x, y, z) {};
		Vec4(float x, float y, float z, float w) : Vec(x, y, z, w) {};
		Vec4(const Vec4& in) {
			*this = in;
		}
		Vec4(const Vec3& in) {
			*this = Vec4(in[0], in[1], in[2], .0f);
		}

		float& operator[](size_t idx);
		const float& operator[](size_t idx) const;
		Vec4& operator=(const Vec4& rhs);
		Vec4& operator+=(const Vec4& rhs);
		Vec4& operator-=(const Vec4& rhs);
		Vec4 operator+(const Vec4& rhs);
		Vec4 operator-(const Vec4& rhs);
		template<typename Tn>
		Vec4 operator/(const Tn& rhs);
		template<typename Tn>
		Vec4 operator*(const Tn& rhs);
		template<typename Tn>
		Vec4& operator/=(const Tn& rhs);
		template<typename Tn>
		Vec4& operator*=(const Tn& rhs);
	};

	class Mat3 : Mat<Mat3> {

	};

	class Mat4 : Mat<Mat4> {

	};
}