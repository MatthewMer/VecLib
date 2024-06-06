// VecLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

#include "VecLib.h"

#include <cmath>
#define _USE_MATH_DEFINES

namespace VecLib {
	namespace {
		const double pi = 3.14159265358979323846;
	}

	Vec3& Vec3::operator=(const Vec3& rhs) {
		return *this;
	}

	Vec3& Vec3::operator+=(const Vec3& rhs) {
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& rhs) {
		return *this;
	}

	template<typename T>
	Vec3& Vec3::operator/=(const T& rhs) {
		return *this;
	}

	template<typename T>
	Vec3& Vec3::operator*=(const T& rhs) {
		return *this;
	}

	Vec3 Vec3::operator+(const Vec3& rhs) {
		return Vec3(
			this->x + rhs.x,
			this->y + rhs.y,
			this->z + rhs.z
		);
	}

	Vec3 Vec3::operator-(const Vec3& rhs) {
		return Vec3(
			this->x - rhs.x,
			this->y - rhs.y,
			this->z - rhs.z
		);
	}

	template<typename T>
	Vec3 Vec3::operator/(const T& rhs) {
		return Vec3(
			this->x / rhs,
			this->y / rhs,
			this->z / rhs
		);
	}

	template<typename T>
	Vec3 Vec3::operator*(const T& rhs) {
		return Vec3(
			this->x * rhs,
			this->y * rhs,
			this->z * rhs
		);
	}

	float Vec3::magnitude() const {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	float Vec3::dot(const Vec3& in) {
		return this->x * in.x + this->y * in.y + this->z * in.z;
	}

	Vec3 Vec3::cross(const Vec3& in) {
		return Vec3(
			this->y * in.z - in.y * this->z,
			this->z * in.x - in.z * this->x,
			this->x * in.y - in.x * this->y
		);
	}

	float Vec3::anglerad(const Vec3& in) {
		float res = acos(this->dot(in) / (this->magnitude() * in.magnitude()));
		if (res > pi)	{ return res - pi; }
		else			{ return res; }
	}

	float Vec3::angledeg(const Vec3& in) {
		return anglerad(in) * 180.f / pi;
	}

	void Vec3::normalize() {
		*this /= this->magnitude();
	}
}