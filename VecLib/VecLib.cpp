// VecLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

#include "VecLib.h"
#include <algorithm>

namespace VecLib {
	namespace {
		

		template<class T>
		void swap(T& lhs, T& rhs) noexcept {
			std::swap(lhs, rhs);
		}
		/*
		template<class T, class ... Tn>
		T cross_det(Tn&& ... input){
			std::vector<std::vector<float>> mat;
			([&]{
					mat.push_back(inputs);
				}
			(), ...);

			size_t args = size - 1;

			T result = T();
			for (size_t row = 0; row < size; row++) {
				float res = .0f;

				for (size_t i = 0; i < args; i++) {
					if (i == row) { continue; }
					

				}
			}
		}
		*/
	}

	/*
	*
	*	Vector 2
	*
	*/

	float& Vec2::operator[](size_t idx) {
		return vec[idx];
	}

	const float& Vec2::operator[](size_t idx) const {
		return vec[idx];
	}

	Vec2& Vec2::operator=(Vec2 rhs) {
		std::swap(*this, rhs);
		return *this;
	}

	Vec2& Vec2::operator+=(const Vec2& rhs) {
		vec[0] += rhs[0];
		vec[1] += rhs[1];
		return *this;
	}

	Vec2& Vec2::operator-=(const Vec2& rhs) {
		vec[0] -= rhs[0];
		vec[1] -= rhs[1];
		return *this;
	}

	template<typename Tn>
	Vec2& Vec2::operator*=(const Tn& rhs) {
		vec[0] *= rhs;
		vec[1] *= rhs;
		return *this;
	}

	template<typename Tn>
	Vec2& Vec2::operator/=(const Tn& rhs) {
		vec[0] /= rhs;
		vec[1] /= rhs;
		return *this;
	}

	/*
	*
	*	Vector 3
	*
	*/

	float& Vec3::operator[](size_t idx) {
		return vec[idx];
	}

	const float& Vec3::operator[](size_t idx) const {
		return vec[idx];
	}

	Vec3& Vec3::operator+=(const Vec3& rhs) {
		vec[0] += rhs[0];
		vec[1] += rhs[1];
		vec[2] += rhs[2];
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& rhs) {
		vec[0] -= rhs[0];
		vec[1] -= rhs[1];
		vec[2] -= rhs[2];
		return *this;
	}

	template<typename Tn>
	Vec3& Vec3::operator/=(const Tn& rhs) {
		vec[0] /= rhs;
		vec[1] /= rhs;
		vec[2] /= rhs;
		return *this;
	}

	template<typename Tn>
	Vec3& Vec3::operator*=(const Tn& rhs) {
		vec[0] *= rhs;
		vec[1] *= rhs;
		vec[2] *= rhs;
		return *this;
	}

	Vec3& Vec3::operator=(const Vec3& rhs) {
		Vec3 temp(rhs);
		swap(*this, temp);
		return *this;
	}

	Vec3 Vec3::operator+(const Vec3& rhs) {
		return Vec3(
			vec[0] + rhs[0],
			vec[1] + rhs[1],
			vec[2] + rhs[2]
		);
	}

	Vec3 Vec3::operator-(const Vec3& rhs) {
		return Vec3(
			vec[0] - rhs[0],
			vec[1] - rhs[1],
			vec[2] - rhs[2]
		);
	}

	template<typename Tn>
	Vec3 Vec3::operator/(const Tn& rhs) {
		return Vec3(
			vec[0] / rhs,
			vec[1] / rhs,
			vec[2] / rhs
		);
	}

	template<typename Tn>
	Vec3 Vec3::operator*(const Tn& rhs) {
		return Vec3(
			vec[0] + rhs,
			vec[1] + rhs,
			vec[2] + rhs
		);
	}
	
	/*
	*
	*	Vector 4
	*
	*/

	float& Vec4::operator[](size_t idx) {
		return vec[idx];
	}

	const float& Vec4::operator[](size_t idx) const {
		return vec[idx];
	}

	Vec4& Vec4::operator=(const Vec4& rhs) {
		Vec4 temp(rhs);
		swap(*this, temp);
		return *this;
	}

	Vec4& Vec4::operator+=(const Vec4& rhs) {
		vec[0] += rhs[0];
		vec[1] += rhs[1];
		vec[2] += rhs[2];
		vec[3] += rhs[3];
		return *this;
	}

	Vec4& Vec4::operator-=(const Vec4& rhs) {
		vec[0] -= rhs[0];
		vec[1] -= rhs[1];
		vec[2] -= rhs[2];
		vec[3] -= rhs[3];
		return *this;
	}

	template<typename Tn>
	Vec4& Vec4::operator/=(const Tn& rhs) {
		vec[0] /= rhs;
		vec[1] /= rhs;
		vec[2] /= rhs;
		vec[3] /= rhs;
		return *this;
	}

	template<typename Tn>
	Vec4& Vec4::operator*=(const Tn& rhs) {
		vec[0] *= rhs;
		vec[1] *= rhs;
		vec[2] *= rhs;
		vec[3] *= rhs;
		return *this;
	}

	Vec4 Vec4::operator+(const Vec4& rhs) {
		return Vec4(
			vec[0] + rhs[0],
			vec[1] + rhs[1],
			vec[2] + rhs[2],
			vec[3] + rhs[3]
		);
	}

	Vec4 Vec4::operator-(const Vec4& rhs) {
		return Vec4(
			vec[0] - rhs[0],
			vec[1] - rhs[1],
			vec[2] - rhs[2],
			vec[3] - rhs[3]
		);
	}

	template<typename Tn>
	Vec4 Vec4::operator/(const Tn& rhs) {
		return Vec4(
			vec[0] / rhs,
			vec[1] / rhs,
			vec[2] / rhs,
			vec[3] / rhs
		);
	}

	template<typename Tn>
	Vec4 Vec4::operator*(const Tn& rhs) {
		return Vec4(
			vec[0] * rhs,
			vec[1] * rhs,
			vec[2] * rhs,
			vec[3] * rhs
		);
	}

	/*
	*
	*	Matrix NxM
	*
	*/
	
	std::vector<float>& MatNM::operator[](size_t idx) {
		return mat[idx];
	}

	const std::vector<float>& MatNM::operator[](size_t idx) const {
		return mat[idx];
	}

	/*
	*
	*	Matrix 2
	*
	*/

	std::vector<float>& Mat2::operator[](size_t idx) {
		return mat[idx];
	}

	const std::vector<float>& Mat2::operator[](size_t idx) const {
		return mat[idx];
	}

	/*
	*
	*	Matrix 3
	*
	*/

	std::vector<float>& Mat3::operator[](size_t idx) {
		return mat[idx];
	}

	const std::vector<float>& Mat3::operator[](size_t idx) const {
		return mat[idx];
	}

	/*
	*
	*	Matrix 4
	*
	*/

	std::vector<float>& Mat4::operator[](size_t idx) {
		return mat[idx];
	}

	const std::vector<float>& Mat4::operator[](size_t idx) const {
		return mat[idx];
	}
}