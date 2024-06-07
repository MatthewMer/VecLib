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
		Vec3 temp(rhs);
		this->swap(temp);
		return *this;
	}

	void Vec3::swap(Vec3& rhs) noexcept {
		std::swap(*this, rhs);
	}

	Vec3& Vec3::operator+=(const Vec3& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}

	template<typename T>
	Vec3& Vec3::operator/=(const T& rhs) {
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		return *this;
	}

	template<typename T>
	Vec3& Vec3::operator*=(const T& rhs) {
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
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
		return (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	float Vec3::dot(const Vec3& in) const {
		return this->x * in.x + this->y * in.y + this->z * in.z;
	}

	Vec3 Vec3::cross(const Vec3& in) const {
		return Vec3(
			this->y * in.z - in.y * this->z,
			this->z * in.x - in.z * this->x,
			this->x * in.y - in.x * this->y
		);
	}

	float Vec3::anglerad(const Vec3& in) const {
		float res = acos(this->dot(in) / (this->magnitude() * in.magnitude()));
		if (res > pi)	{ return (float)(res - pi); }
		else			{ return res; }
	}

	float Vec3::angledeg(const Vec3& in) const {
		return (float)(anglerad(in) * 180.f / pi);
	}

	void Vec3::normalize() {
		*this /= this->magnitude();
	}

	std::string Vec3::to_string() const {
		return std::string(
			"{" +
			std::to_string(x) + ";" +
			std::to_string(y) + ";" +
			std::to_string(z) + ";" +
			"}"
		);
	}
}