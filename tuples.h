#include "TheRayTracerChallenge.h"

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
	return (l.x == r.x) && (l.y == r.y) && (l.z == r.z) && (l.w == r.w);
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