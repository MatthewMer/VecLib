#include "pch.h"

#include "../VecLib/VecLib.h"

using VecLib::Vec2;

TEST(Vec2float, construct) {
	Vec2<float> tmp;
	const auto& data = tmp.as_container();

	Vec2<float> tmp2 = Vec2<float>(1, 1);
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		std::is_constructible<Vec2<float>>::value == 1 && 
		data.size() == 2 &&
		data[0] == 0 && 
		data[1] == 0 &&
		data2.size() == 2 &&
		data2[0] == 1 && 
		data2[1] == 1,
	true);
}

TEST(Vec2float, copyconstruct) {
	Vec2<float> tmp = Vec2<float>(1, 1);

	Vec2<float> tmp2(tmp);
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		std::is_copy_constructible<Vec2<float>>::value == 1 &&
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}

TEST(Vec2float, moveconstruct) {
	Vec2<float> tmp = Vec2<float>(1, 1);

	Vec2<float> tmp2(std::move(tmp));
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		std::is_move_constructible<Vec2<float>>::value == 1 &&
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}

TEST(Vec2float, copyassign) {
	Vec2<float> tmp = Vec2<float>(1, 1);

	Vec2<float> tmp2 = tmp;
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		std::is_copy_assignable<Vec2<float>>::value == 1 &&
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}

TEST(Vec2float, moveassign) {
	Vec2<float> tmp = Vec2<float>(1, 1);

	Vec2<float> tmp2 = std::move(tmp);
	const auto& data2 = tmp2.as_container();

	EXPECT_EQ(
		std::is_move_assignable<Vec2<float>>::value == 1 &&
		data2.size() == 2 &&
		data2[0] == 1 &&
		data2[1] == 1
	, true);
}