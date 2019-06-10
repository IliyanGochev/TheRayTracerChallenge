#include "TheRayTracerChallenge.h"
#include "tuples.h"


TEST_SUITE("Tuples") {
	TEST_CASE("A tuple with w=1.0 is a point") {
		auto a = Tuple(4.3, -4.2, 3.1, 1.0);
		CHECK_EQ(a.x, doctest::Approx(4.3));
		CHECK_EQ(a.y, doctest::Approx(-4.2));
		CHECK_EQ(a.z, doctest::Approx(3.1));
		CHECK_EQ(a.w, doctest::Approx(1.0));
		CHECK_EQ(true, is_point(a));
		CHECK_EQ(false, is_vector(a));
	}

	TEST_CASE("A tuple with w=0.0 is a vector") {
		auto a = Tuple(4.3, -4.2, 3.1, 0.0);
		CHECK_EQ(a.x, doctest::Approx(4.3));
		CHECK_EQ(a.y, doctest::Approx(-4.2));
		CHECK_EQ(a.z, doctest::Approx(3.1));
		CHECK_EQ(a.w, doctest::Approx(0.0));
		CHECK_EQ(false, is_point(a));
		CHECK_EQ(true, is_vector(a));
	}

	TEST_CASE("point() creates a tuple with w=1.0") {
		auto p = point(4, -4, 3);
		CHECK_EQ(p, Tuple(4, -4, 3, 1));
	}

	TEST_CASE("vector() creates a tuple with w=0.0") {
		auto v = vector(4, -4, 3);
		CHECK_EQ(v, Tuple(4, -4, 3, 0));
	}

	TEST_CASE("Adding two tuples") {
		auto a1 = Tuple(3, -2, 5, 1);
		auto a2 = Tuple(-2, 3, 1, 0);
		CHECK_EQ(a1 + a2, Tuple(1, 1, 6, 1));
	}

	TEST_CASE("Subtracting two points") {
		auto p1 = point(3, 2, 1);
		auto p2 = point(5, 6, 7);
		CHECK_EQ(p1 - p2, vector(-2, -4, -6));
	}

	TEST_CASE("Subtracting vector from a point") {
		auto p = point(3, 2, 1);
		auto v = vector(5, 6, 7);
		CHECK_EQ(p - v, point(-2, -4, -6));
	}

	TEST_CASE("Subtracting two vectors") {
		auto v1 = vector(3, 2, 1);
		auto v2 = vector(5, 6, 7);
		CHECK_EQ(v1 - v2, vector(-2, -4, -6));
	}

	TEST_CASE("Negating a tuple") {
		auto a = Tuple(1, -2, 3, -4);
		CHECK_EQ(-a, Tuple(-1, 2, -3, 4));
	}

	TEST_CASE("Multiplying a tuple by a scalar") {
		auto a = Tuple(1, -2, 3, -4);
		CHECK_EQ(a * 3.5, Tuple(3.5, -7, 10.5, -14));
	}

	TEST_CASE("Multiplying a tuple by a fraction") {
		auto a = Tuple(1, -2, 3, -4);
		CHECK_EQ(a * 0.5, Tuple(0.5, -1, 1.5, -2));
	}

	TEST_CASE("Dividing a tuple by a scalar") {
		auto a = Tuple(1, -2, 3, -4);
		CHECK_EQ(a / 2, Tuple(0.5, -1, 1.5, -2));
	}

}