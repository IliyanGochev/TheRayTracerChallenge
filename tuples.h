#include "TheRayTracerChallenge.h"

struct tuple {
	real x, y, z, w;
};

inline tuple create_tuple(real x, real y, real z, real w) {
	tuple result = { 
		.x =x,
		.y =y,
		.z =z,
		.w =w };
	return result;
}

inline tuple create_point(real x, real y, real z) {
	return create_tuple(x, y, z, 1.0);
}

inline tuple create_vector(real x, real y, real z) {
	return create_tuple(x, y, z, 0.0);
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