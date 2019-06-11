#include "colors.h"

TEST_SUITE("Colors") {
	TEST_CASE("Colors are RGB tuples") {
		auto c = Color(-0.5, 0.4f, 1.7f);
		CHECK_EQ(c.red, doctest::Approx(-0.5));
		CHECK_EQ(c.green, doctest::Approx(0.4));
		CHECK_EQ(c.blue, doctest::Approx(1.7));
	}

	TEST_CASE("Adding colors") {
		auto c1 = Color(0.9f, 0.6f, 0.75f);
		auto c2 = Color(0.7f, 0.1f, 0.25f);
		auto r = c1 + c2;
		CHECK_EQ(r, Color(1.6, 0.7, 1.0));
	}

	TEST_CASE("Subtracting colors") {
		auto c1 = Color(0.9f, 0.6f, 0.75f);
		auto c2 = Color(0.7f, 0.1f, 0.25f);
		auto r = c1 - c2;
		CHECK_EQ(r, Color(0.2, 0.5, 0.5));
	}

	TEST_CASE("Multiplying a color by a scalar") {
		auto c = Color(0.2, 0.3, 0.4);
		auto r = c * 2;
		CHECK_EQ(r, Color(0.4, 0.6, 0.8));
	}

	TEST_CASE("Multiplying colors") {
		auto c1 = Color(1, 0.2, 0.4);
		auto c2 = Color(0.9, 1.0, 0.1);
		auto r = c1 * c2;
		CHECK_EQ(r, Color(0.9, 0.2, 0.04));
	}
}
