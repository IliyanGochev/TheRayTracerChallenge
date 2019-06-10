#include "TheRayTracerChallenge.h"
#include "tuple.h"


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
}