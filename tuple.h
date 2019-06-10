#include "TheRayTracerChallenge.h"

struct tuple {
	real x, y, z, w;
};

inline tuple create_tuple(real x, real y, real z, real w) {
	tuple result = { x,y,z,w };
	return result;
}

inline tuple create_point(real x, real y, real z) {
	return create_tuple(x, y, z, 1);
}

inline tuple create_vector(real x, real y, real z) {
	return create_tuple(x, y, z, 1.0);
}

inline bool is_point(tuple p) { return p.w == 1.0; }
inline bool is_vector(tuple v) { return v.w == 0.0; }

inline bool operator==(tuple const& l, tuple const& r) {
	return (l.x == r.x) && (l.y == r.y) && (l.z == r.z) && (l.w == r.w);
}