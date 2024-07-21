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

		template<class T>
		class Vec {
		public:
			Vec() = default;
			Vec(const size_t& Sn) {
				vec = std::vector<T>(Sn, 0);
			}
			Vec(const size_t& Sn, const T& x) : Vec(Sn) {
				vec[0] = x;
			}
			Vec(const size_t& Sn, const T& x, const T& y) : Vec(Sn) {
				vec[0] = x;
				vec[1] = y;
			}
			Vec(const size_t& Sn, const T& x, const T& y, const T& z) : Vec(Sn) {
				vec[0] = x;
				vec[1] = y;
				vec[2] = z;
			}
			Vec(const size_t& Sn, const T& x, const T& y, const T& z, const T& w) : Vec(Sn) {
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

			template <class T_>
			double dot(const T_& in) const {
				double res = .0f;
				size_t i = 0;
				for (const auto & n : vec) {
					res += n * in[i++];
				}
				return res;
			}

			double anglerad(const Vec& in) const {
				double res = acos(this->dot(in) / (this->magnitude() * in.magnitude()));
				if (res > pi)	{ return res - pi; } 
				else			{ return res; }
			}

			double angledeg(const Vec& in) const {
				return this->anglerad(in) * 180.f / pi;
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

			friend bool operator==(const Vec& lhs, const Vec& rhs) {
				for (size_t i = 0; i < lhs.vec.size(); ++i) {
					if (lhs.vec[i] != rhs.vec[i]) { return false; }
				}
				return true;
			}

			friend bool operator!=(const Vec& lhs, const Vec& rhs) {
				for (size_t i = 0; i < lhs.vec.size(); ++i) {
					if (lhs.vec[i] != rhs.vec[i]) { return true; }
				}
				return false;
			}

			friend bool operator>=(const Vec& lhs, const Vec& rhs) {
				return lhs.magnitude() >= rhs.magnitude();
			}

			friend bool operator<=(const Vec& lhs, const Vec& rhs) {
				return lhs.magnitude() <= rhs.magnitude();
			}

			friend bool operator>(const Vec& lhs, const Vec& rhs) {
				return lhs.magnitude() > rhs.magnitude();
			}

			friend bool operator<(const Vec& lhs, const Vec& rhs) {
				return lhs.magnitude() < rhs.magnitude();
			}


			Vec& operator+=(const Vec& rhs) {
				for (size_t i = 0; i < this->vec.size() && i < rhs.vec.size(); ++i) {
					this->vec[i] += rhs.vec[i];
				}
				return *this;
			}

			Vec& operator-=(const Vec& rhs) {
				for (size_t i = 0; i < this->vec.size() && i < rhs.vec.size(); ++i) {
					this->vec[i] -= rhs.vec[i];
				}
				return *this;
			}

			Vec& operator*=(const double& rhs) {
				for (size_t i = 0; i < this->vec.size(); ++i) {
					this->vec[i] *= rhs;
				}
				return *this;
			}

			Vec& operator/=(const double& rhs) {
				for (size_t i = 0; i < this->vec.size(); ++i) {
					this->vec[i] /= rhs;
				}
				return *this;
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

	template <class T>
	class Vec2 : public Vec<T> {
	public:
		Vec2() : Vec<T>(2) {};
		Vec2(const T& x) : Vec<T>(2, x) {};
		Vec2(const T& x, const T& y) : Vec<T>(2, x, y) {};
		~Vec2() = default;

		Vec2(const Vec2& other) : Vec<T>(2) {
			std::copy(other.vec.begin(), other.vec.end(), this->vec.begin());
		};
		Vec2(Vec2&& other) noexcept {
			this->vec = std::move(other.vec);
		};

		T& operator[](size_t idx);
		const T& operator[](size_t idx) const;

		Vec2<T>& operator=(const Vec2& rhs);
		Vec2<T>& operator=(Vec2<T>&& rhs) noexcept;
		/*
		Vec2<T>& operator+=(const Vec2& rhs);
		Vec2<T>& operator-=(const Vec2& rhs);
		Vec2<T>& operator/=(const double& rhs);
		Vec2<T>& operator*=(const double& rhs);
		*/
		friend Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
			return Vec2(lhs[0] + rhs[0], lhs[1] + rhs[1]);
		}
		friend Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
			return Vec2(lhs[0] - rhs[0], lhs[1] - rhs[1]);
		}
		friend Vec2 operator/(const Vec2& lhs, const double& rhs) {
			return Vec2(lhs[0] / rhs, lhs[1] / rhs);
		}
		friend Vec2 operator*(const Vec2& lhs, const double& rhs) {
			return Vec2(lhs[0] * rhs, lhs[1] * rhs);
		}
	};

	template <class T>
	T& Vec2<T>::operator[](size_t idx) {
		return this->vec[idx];
	}

	template <class T>
	const T& Vec2<T>::operator[](size_t idx) const {
		return this->vec[idx];
	}

	template <class T>
	Vec2<T>& Vec2<T>::operator=(const Vec2& rhs) {
		std::copy(rhs.vec.begin(), rhs.vec.end(), this->vec.begin());
		return *this;
	}

	template <class T>
	Vec2<T>& Vec2<T>::operator=(Vec2<T>&& rhs) noexcept {
		if (this != &rhs) {
			this->vec = std::move(rhs.vec);
		}
		return *this;
	}
	/*
	template <class T>
	Vec2<T>& Vec2<T>::operator+=(const Vec2& rhs) {
		std::transform(rhs.vec.begin(), rhs.vec.end(), this->vec.begin(), )
		this->vec[0] += rhs[0];
		this->vec[1] += rhs[1];
		return *this;
	}

	template <class T>
	Vec2<T>& Vec2<T>::operator-=(const Vec2& rhs) {
		this->vec[0] -= rhs[0];
		this->vec[1] -= rhs[1];
		return *this;
	}

	template <class T>
	Vec2<T>& Vec2<T>::operator*=(const double& rhs) {
		this->vec[0] *= rhs;
		this->vec[1] *= rhs;
		return *this;
	}

	template <class T>
	Vec2<T>& Vec2<T>::operator/=(const double& rhs) {
		this->vec[0] /= rhs;
		this->vec[1] /= rhs;
		return *this;
	}
	*/
	/*
	class Vec3 : public Vec<Vec3> {
	public:
		Vec3() : Vec(3) {};
		Vec3(float x) : Vec(3, x) {};
		Vec3(float x, float y) : Vec(3, x, y) {};
		Vec3(float x, float y, float z) : Vec(3, x, y, z) {};
		Vec3(const Vec2& in) {
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
	
	class Vec4 : public Vec<Vec4> {
	public:
		Vec4() : Vec(4) {};
		Vec4(float x) : Vec(4, x) {};
		Vec4(float x, float y) : Vec(4, x, y) {};
		Vec4(float x, float y, float z) : Vec(4, x, y, z) {};
		Vec4(float x, float y, float z, float w) : Vec(4, x, y, z, w) {};
		Vec4(const Vec2& in) {
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