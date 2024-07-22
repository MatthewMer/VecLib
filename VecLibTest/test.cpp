#include "pch.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "../VecLib/VecLib.h"

using VecLib::Vec;

TEST(Vec2float, construct) {
	Vec<2, float> tmp;
	const auto& data = tmp.as_container();

	Vec<2, float> tmp2 = Vec<2, float>( 1, 1 );
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		data[0] == 0 && 
		data[1] == 0 &&
		data2.size() == 2 &&
		data2[0] == 1 && 
		data2[1] == 1,
	true);
}

TEST(Vec2float, copyConstruct) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> tmp2(tmp);
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}

TEST(Vec2float, moveConstruct) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> tmp2(std::move(tmp));
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}

TEST(Vec2float, copyAssign) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> tmp2 = tmp;
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}

TEST(Vec2float, moveAssign) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> tmp2 = std::move(tmp);
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}

TEST(Vec2float, comparisonEquals) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> equal = Vec<2, float>( 1, 1 );

	EXPECT_EQ(
		tmp == equal
		, true);
}

TEST(Vec2float, comparisonNotEquals) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> equal = Vec<2, float>( 1, 0 );

	EXPECT_EQ(
		tmp != equal
		, true);
}

TEST(Vec2float, comparisonSmallerEquals) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> smaller = Vec<2, float>( 1, 0 );
	Vec<2, float> equal = Vec<2, float>( 1, 1 );

	EXPECT_EQ(
		equal <= tmp &&
		smaller <= tmp
		, true);
}

TEST(Vec2float, comparisonSmaller) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> smaller = Vec<2, float>( 1, 0 );
	Vec<2, float> equal = Vec<2, float>( 1, 1 );

	EXPECT_EQ(
		!(equal < tmp) &&
		smaller < tmp
		, true);
}

TEST(Vec2float, comparisonGreaterEquals) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> greater = Vec<2, float>( 1, 2 );
	Vec<2, float> equal = Vec<2, float>( 1, 1 );

	EXPECT_EQ(
		equal >= tmp &&
		greater >= tmp
		, true);
}

TEST(Vec2float, comparisonGreater) {
	Vec<2, float> tmp = Vec<2, float>( 1, 1 );

	Vec<2, float> greater = Vec<2, float>( 1, 2 );
	Vec<2, float> equal = Vec<2, float>( 1, 1 );

	EXPECT_EQ(
		!(equal > tmp) &&
		greater > tmp
		, true);
}

TEST(Vec2float, binaryArithmeticPlus) {
	Vec<2, float> tmp = Vec<2, float>( 1, 2 );

	Vec<2, float> tmp2 = Vec<2, float>( 2, 2 );
	tmp2 = tmp + tmp2;

	Vec<2, float> expected = Vec<2, float>( 3, 4 );
	const auto& data = tmp2.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp2
		, true);
}

TEST(Vec2float, binaryArithmeticPlusEquals) {
	Vec<2, float> tmp = Vec<2, float>( 1, 2 );

	Vec<2, float> tmp2 = Vec<2, float>( 2, 2 );
	tmp2 += tmp;

	Vec<2, float> expected = Vec<2, float>( 3, 4 );
	const auto& data = tmp2.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp2
		, true);
}

TEST(Vec2float, binaryArithmeticMinus) {
	Vec<2, float> tmp = Vec<2, float>( 3, 4 );

	Vec<2, float> tmp2 = Vec<2, float>( 2, 2 );
	tmp2 = tmp - tmp2;

	Vec<2, float> expected = Vec<2, float>( 1, 2 );
	const auto& data = tmp2.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp2
		, true);
}

TEST(Vec2float, binaryArithmeticMinusEquals) {
	Vec<2, float> tmp = Vec<2, float>( 2, 2 );

	Vec<2, float> tmp2 = Vec<2, float>( 3, 4 );
	tmp2 -= tmp;

	Vec<2, float> expected = Vec<2, float>( 1, 2 );
	const auto& data = tmp2.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp2
		, true);
}

TEST(Vec2float, binaryArithmeticMult) {
	Vec<2, float> tmp = Vec<2, float>( 3, 4 );

	tmp = tmp * 2;

	Vec<2, float> expected = Vec<2, float>( 6, 8 );
	const auto& data = tmp.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp
		, true);
}

TEST(Vec2float, binaryArithmeticMultEquals) {
	Vec<2, float> tmp = Vec<2, float>( 3, 4 );

	tmp *= 2;

	Vec<2, float> expected = Vec<2, float>( 6, 8 );
	const auto& data = tmp.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp
		, true);
}

TEST(Vec2float, binaryArithmeticDiv) {
	Vec<2, float> tmp = Vec<2, float>( 6, 8 );

	tmp = tmp / 2;

	Vec<2, float> expected = Vec<2, float>( 3, 4 );
	const auto& data = tmp.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp
		, true);
}

TEST(Vec2float, binaryArithmeticDivEquals) {
	Vec<2, float> tmp = Vec<2, float>( 6, 8 );

	tmp /= 2;

	Vec<2, float> expected = Vec<2, float>( 3, 4 );
	const auto& data = tmp.as_container();

	EXPECT_EQ(
		data.size() == 2 &&
		expected == tmp
		, true);
}

TEST(Vec2float, subscript) {
	Vec<2, float> tmp = Vec<2, float>( 6, 8 );

	EXPECT_EQ(
		tmp[0] == 6 &&
		tmp[1] == 8
		, true);
}

TEST(Vec2float, subscriptConst) {
	const Vec<2, float> tmp = Vec<2, float>( 6, 8 );

	EXPECT_EQ(
		tmp[0] == 6 &&
		tmp[1] == 8
		, true);
}

TEST(Vec2float, string) {
	const Vec<2, float> tmp = Vec<2, float>( 6, 8 );

	std::string expexted = "[" + std::to_string(6.f) + ";" + std::to_string(8.f) + "]";

	EXPECT_EQ(
		tmp.to_string().compare(expexted) == 0
		, true);
}

TEST(Vec2float, magnitude) {
	Vec<2, float> tmp = Vec<2, float>( 6, 8 );

	double expected = sqrt(pow(6, 2) + pow(8, 2));

	EXPECT_EQ(
		expected == tmp.magnitude()
		, true);
}

TEST(Vec2float, dot) {
	Vec<2, float> tmp = Vec<2, float>( 1, 4 );
	Vec<4, float> tmp2 = Vec<4, float>( 2, 3, 1, -3 );

	double expected = tmp[0] * tmp2[0] + tmp[1] * tmp2[1] + tmp[0] * tmp2[2] + tmp[1] * tmp2[3];

	EXPECT_EQ(
		expected == tmp.dot(tmp2)
		, true);
}

TEST(Vec2float, anglerad) {
	Vec<2, float> tmp = Vec<2, float>( 1, 0 );
	Vec<2, float> tmp2 = Vec<2, float>( -1, 0 );

	double expected = M_PI;

	EXPECT_EQ(
		expected == tmp.anglerad(tmp2)
		, true);
}

TEST(Vec2float, angledeg) {
	Vec<2, float> tmp = Vec<2, float>( 1, 0 );
	Vec<2, float> tmp2 = Vec<2, float>( -1, 0 );

	double expected = 180.f;

	EXPECT_EQ(
		expected == tmp.angledeg(tmp2)
		, true);
}