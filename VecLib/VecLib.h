#pragma once

namespace VecLib {
	class Vec3 {
	public:
		float x;
		float y;
		float z;

		Vec3():x(0),y(0),z(0){}
		Vec3(float x, float y, float z) :x(x), y(y), z(z) {}
		Vec3(const Vec3& in){
			*this = in;
		}

		Vec3& operator=(const Vec3& rhs);

		Vec3& operator+=(const Vec3& rhs);
		Vec3& operator-=(const Vec3& rhs);

		Vec3 operator+(const Vec3& rhs);
		Vec3 operator-(const Vec3& rhs);

		template<typename T>
		Vec3 operator/(const T& rhs);
		template<typename T>
		Vec3 operator*(const T& rhs);

		template<typename T>
		Vec3& operator/=(const T& rhs);
		template<typename T>
		Vec3& operator*=(const T& rhs);



		float magnitude() const;
		float dot(const Vec3& in);
		Vec3 cross(const Vec3& in);
		float anglerad(const Vec3& in);
		float angledeg(const Vec3& in);
		void normalize();
	};
}