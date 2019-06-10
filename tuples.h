#include "TheRayTracerChallenge.h"
#include "common.h"

struct tuple {
	real x, y, z, w;
};

inline tuple Tuple(real x, real y, real z, real w) {
	tuple result = { 
		.x =x,
		.y =y,
		.z =z,
		.w =w };
	return result;
}

inline tuple point(real x, real y, real z) {
	return Tuple(x, y, z, 1.0);
}

inline tuple vector(real x, real y, real z) {
	return Tuple(x, y, z, 0.0);
}

inline bool is_point(tuple p) { return p.w == 1.0; }
inline bool is_vector(tuple v) { return v.w == 0.0; }

inline bool operator==(tuple const& l, tuple const& r) {
	return eps_equal(l.x, r.x) && eps_equal(l.y, r.y) && eps_equal(l.z, r.z) && eps_equal(l.w, r.w);
}

inline tuple operator+(tuple const& l, tuple const& r) {
	tuple result = { 
		.x =l.x + r.x,
		.y =l.y + r.y,
		.z =l.z + r.z,
		.w =l.w + r.w 
	};
	return result;
}

inline tuple operator-(tuple const& l, tuple const& r) {
	tuple result = {
		.x = l.x - r.x,
		.y = l.y - r.y,
		.z = l.z - r.z,
		.w = l.w - r.w
	};
	return result;
}
inline tuple operator-(tuple const& l) {
	tuple result = {
		.x = -l.x,
		.y = -l.y,
		.z = -l.z,
		.w = -l.w,
	};
	return result;
}

inline tuple operator*(tuple const& t, real const& s) {
	tuple result = {
		.x = t.x * s,
		.y = t.y * s,
		.z = t.z * s,
		.w = t.w * s,
	};
	return result;
}

inline tuple operator/(tuple const& t, real const& s) {
	tuple result = {
		.x = t.x / s,
		.y = t.y / s,
		.z = t.z / s,
		.w = t.w / s,
	};
	return result;
}

inline real magnitude(tuple t) {
	return std::sqrt(t.x * t.x + t.y * t.y + t.z * t.z + t.w * t.w);
}

inline tuple normalize(tuple const& t) {
	tuple result{};
	auto m = magnitude(t);
	result = {
		.x = t.x / m,
		.y = t.y / m,
		.z = t.z / m,
		.w = t.w / m
	};
	return result;
}