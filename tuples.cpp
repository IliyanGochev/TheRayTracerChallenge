#include "TheRayTracerChallenge.h"
#include "tuples.h"


TEST_SUITE("Tuples") {
	TEST_CASE("A tuple with w=1.0 is a point") {
		auto a = create_tuple(4.3, -4.2, 3.1, 1.0);
		CHECK_EQ(a.x, doctest::Approx(4.3));
		CHECK_EQ(a.y, doctest::Approx(-4.2));
		CHECK_EQ(a.z, doctest::Approx(3.1));
		CHECK_EQ(a.w, doctest::Approx(1.0));
		CHECK_EQ(true, is_point(a));
		CHECK_EQ(false, is_vector(a));
	}

	TEST_CASE("A tuple with w=0.0 is a vector") {
		auto a = create_tuple(4.3, -4.2, 3.1, 0.0);
		CHECK_EQ(a.x, doctest::Approx(4.3));
		CHECK_EQ(a.y, doctest::Approx(-4.2));
		CHECK_EQ(a.z, doctest::Approx(3.1));
		CHECK_EQ(a.w, doctest::Approx(0.0));
		CHECK_EQ(false, is_point(a));
		CHECK_EQ(true, is_vector(a));
	}

	TEST_CASE("create_point() creates a tuple with w=1.0") {
		auto p = create_point(4, -4, 3);
		CHECK_EQ(p, create_tuple(4, -4, 3, 1));
	}

	TEST_CASE("create_vector() creates a tuple with w=0.0") {
		auto v = create_vector(4, -4, 3);
		CHECK_EQ(v, create_tuple(4, -4, 3, 0));
	}

	TEST_CASE("Adding two tuples") {
		auto a1 = create_tuple(3, -2, 5, 1);
		auto a2 = create_tuple(-2, 3, 1, 0);
		CHECK_EQ(a1 + a2, create_tuple(1, 1, 6, 1));
	}

	TEST_CASE("Subtracting two points") {
		auto p1 = create_point(3, 2, 1);
		auto p2 = create_point(5, 6, 7);
		CHECK_EQ(p1 - p2, create_vector(-2, -4, -6));
	}

	TEST_CASE("Subtracting vector from a point") {
		auto p = create_point(3, 2, 1);
		auto v = create_vector(5, 6, 7);
		CHECK_EQ(p - v, create_point(-2, -4, -6));
	}

	TEST_CASE("Subtracting two vectors") {
		auto v1 = create_vector(3, 2, 1);
		auto v2 = create_vector(5, 6, 7);
		CHECK_EQ(v1 - v2, create_vector(-2, -4, -6));
	}

	TEST_CASE("Negating a tuple") {
		auto a = create_tuple(1, -2, 3, -4);
		CHECK_EQ(-a, create_tuple(-1, 2, -3, 4));
	}
}