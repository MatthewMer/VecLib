#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <vector>
#include <array>
#include <stdexcept>
#include <cstdarg>
#include <concepts>

#include <iostream>

namespace VecLib {
	namespace {
		template<class T>
		class Vector {
		public:
			Vector() = default;
			Vector(const size_t& Sn) {
				vec = std::vector<T>(Sn, 0);
			}
			Vector(const size_t& Sn, const std::initializer_list<T>& vals) : Vector(Sn) {
				size_t i = 0;
				for (const auto & n : vals) {
					if (i < Sn) {
						this->vec[i] = n;
					}
					else {
						break;
					}
					++i;
				}
			}
			Vector(const size_t& Sn, std::convertible_to<T> auto ...vals) : Vector(Sn)
			{
				size_t i = 0;
				for (const T& n : { T(vals)... }) {
					if (i < Sn) {
						this->vec[i] = n;
					}
					++i;
				}
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

			double dot(const Vector& in) const {
				size_t N = this->vec.size();
				size_t M = in.vec.size();

				double res = .0f;
				for (size_t i = 0; i < (N < M ? M : N); ++i) {
					res += this->vec[i % N] * in.vec[i % M];
				}
				return res;
			}

			double anglerad(const Vector& in) const {
				double res = acos(this->dot(in) / (this->magnitude() * in.magnitude()));
				if (res > M_PI)	{ return res - M_PI; }
				else			{ return res; }
			}

			double angledeg(const Vector& in) const {
				return this->anglerad(in) * 180.f / M_PI;
			}

			void normalize() {
				auto m = this->magnitude();
				for (auto& n : vec) {
					n /= m;
				}
			}

			const std::vector<float>& as_container() {
				return vec;
			}

			/*
			template<class ...Ts>
			T cross(Ts &&...in) {
				T res = T();

				std::vector<std::vector<float>> mat;
				(mat.push_back(in), ...);

				for (size_t row = 0; row < vec.size(); row++) {
					for (size_t i = 0; i < vec.size(); i++) {

					}
				}
			}
			*/

			friend bool operator==(const Vector& lhs, const Vector& rhs) {
				for (size_t i = 0; i < lhs.vec.size(); ++i) {
					if (lhs.vec[i] != rhs.vec[i]) { return false; }
				}
				return true;
			}

			friend bool operator!=(const Vector& lhs, const Vector& rhs) {
				for (size_t i = 0; i < lhs.vec.size(); ++i) {
					if (lhs.vec[i] != rhs.vec[i]) { return true; }
				}
				return false;
			}

			friend bool operator>=(const Vector& lhs, const Vector& rhs) {
				return lhs.magnitude() >= rhs.magnitude();
			}

			friend bool operator<=(const Vector& lhs, const Vector& rhs) {
				return lhs.magnitude() <= rhs.magnitude();
			}

			friend bool operator>(const Vector& lhs, const Vector& rhs) {
				return lhs.magnitude() > rhs.magnitude();
			}

			friend bool operator<(const Vector& lhs, const Vector& rhs) {
				return lhs.magnitude() < rhs.magnitude();
			}


			Vector& operator+=(const Vector& rhs) {
				for (size_t i = 0; i < this->vec.size(); ++i) {
					this->vec[i] += rhs.vec[i];
				}
				return *this;
			}

			Vector& operator-=(const Vector& rhs) {
				for (size_t i = 0; i < this->vec.size(); ++i) {
					this->vec[i] -= rhs.vec[i];
				}
				return *this;
			}

			Vector& operator*=(const double& rhs) {
				for (size_t i = 0; i < this->vec.size(); ++i) {
					this->vec[i] *= rhs;
				}
				return *this;
			}

			Vector& operator/=(const double& rhs) {
				for (size_t i = 0; i < this->vec.size(); ++i) {
					this->vec[i] /= rhs;
				}
				return *this;
			}

			T& operator[](size_t idx) {
				return this->vec[idx];
			}

			const T& operator[](size_t idx) const {
				return this->vec[idx];
			}

			std::vector<T>::iterator begin() {
				return this->vec.begin();
			}

			std::vector<T>::iterator end() {
				return this->vec.end();
			}

		protected:
			std::vector<T> vec;
		};

		

		/*
		template<class T>
		class Mat {
		public:
			Mat() = default;
			Mat(size_t Sn, size_t Sm) {
				mat = std::vector<std::vector<float>>(Sn, std::vector<float>(Sm, .0f));
			}
			Mat(size_t Sn, size_t Sm, std::vector<float> x) : Mat(Sn, Sm) {
				mat[0] = x.resize(Sm);
			}
			Mat(size_t Sn, size_t Sm, std::vector<float> x, std::vector<float> y) : Mat(Sn, Sm) {
				mat[0] = x.resize(Sm);
				mat[1] = y.resize(Sm);
			}
			Mat(size_t Sn, size_t Sm, std::vector<float> x, std::vector<float> y, std::vector<float> z) : Mat(Sn, Sm) {
				mat[0] = x.resize(Sm);
				mat[1] = y.resize(Sm);
				mat[2] = z.resize(Sm);
			}
			Mat(size_t Sn, size_t Sm, std::vector<float> x, std::vector<float> y, std::vector<float> z, std::vector<float> w) : Mat(Sn, Sm) {
				mat[0] = x.resize(Sm);
				mat[1] = y.resize(Sm);
				mat[2] = z.resize(Sm);
				mat[3] = w.resize(Sm);
			}

		protected:
			std::vector<std::vector<T>> mat;
		};
		*/
	}

	template <size_t Sn, class T>
	class Vec : public Vector<T> {
	public:
		Vec() : Vector<T>(Sn) {};
		Vec(const std::initializer_list<T>& vals) : Vector<T>(Sn, vals) {};
		Vec(std::convertible_to<T> auto ...vals) : Vector<T>(Sn, vals...) {};
		~Vec() = default;

		Vec(const Vec& other) : Vector<T>(Sn) {
			std::copy(other.vec.begin(), other.vec.end(), this->vec.begin());
		};
		Vec(Vec&& other) noexcept {
			this->vec = std::move(other.vec);
		};

		Vec<Sn, T>& operator=(const Vec& rhs);
		Vec<Sn, T>& operator=(Vec<Sn, T>&& rhs) noexcept;
	
		friend Vec operator+(const Vec& lhs, const Vec& rhs) {
			auto res = lhs;
			res += rhs;
			return res;
		}
		friend Vec operator-(const Vec& lhs, const Vec& rhs) {
			auto res = lhs;
			res -= rhs;
			return res;
		}
		friend Vec operator*(const Vec& lhs, const double& rhs) {
			auto res = lhs;
			res *= rhs;
			return res;
		}
		friend Vec operator/(const Vec& lhs, const double& rhs) {
			auto res = lhs;
			res /= rhs;
			return res;
		}
		
	};

	template <size_t n, class T>
	Vec<n, T>& Vec<n, T>::operator=(const Vec& rhs) {
		std::copy(rhs.vec.begin(), rhs.vec.end(), this->vec.begin());
		return *this;
	}

	template <size_t n, class T>
	Vec<n, T>& Vec<n, T>::operator=(Vec<n, T>&& rhs) noexcept {
		if (this != &rhs) {
			this->vec = std::move(rhs.vec);
		}
		return *this;
	}


	/*
	class Vec3 : public Vector<Vec3> {
	public:
		Vec3() : Vector(3) {};
		Vec3(float x) : Vector(3, x) {};
		Vec3(float x, float y) : Vector(3, x, y) {};
		Vec3(float x, float y, float z) : Vector(3, x, y, z) {};
		Vec3(const Vec& in) {
			*this = Vec3(in[0], in[1], .0f);
		}
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
	
	class Vec4 : public Vector<Vec4> {
	public:
		Vec4() : Vector(4) {};
		Vec4(float x) : Vector(4, x) {};
		Vec4(float x, float y) : Vector(4, x, y) {};
		Vec4(float x, float y, float z) : Vector(4, x, y, z) {};
		Vec4(float x, float y, float z, float w) : Vector(4, x, y, z, w) {};
		Vec4(const Vec& in) {
			*this = Vec4(in[0], in[1], .0f, .0f);
		}
		Vec4(const Vec3& in) {
			*this = Vec4(in[0], in[1], in[2], .0f);
		}
		Vec4(const Vec4& in) {
			*this = in;
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
	
	class MatNM : public Mat<MatNM> {
	public:
		std::vector<float>& operator[](size_t idx);
		const std::vector<float>& operator[](size_t idx) const;
	};
	
	class Mat2 : public Mat<Mat2> {
	public:
		std::vector<float>& operator[](size_t idx);
		const std::vector<float>& operator[](size_t idx) const;
	};

	class Mat3 : public Mat<Mat3> {
	public:
		std::vector<float>& operator[](size_t idx);
		const std::vector<float>& operator[](size_t idx) const;
	};

	class Mat4 : public Mat<Mat4> {
	public:
		std::vector<float>& operator[](size_t idx);
		const std::vector<float>& operator[](size_t idx) const;
	};
	*/
}