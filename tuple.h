#include "TheRayTracerChallenge.h"

struct tuple {
	real x, y, z, w;
};

tuple create_tuple(real x, real y, real z, real w) {
	tuple result = { x,y,z,w };
	return result;
}

tuple create_point(real x, real y, real z) {
	return create_tuple(x, y, z, 1);
}

tuple create_vector(real x, real y, real z) {
	return create_tuple(x, y, z, 1.0);
}

bool is_point(tuple p) { return p.w == 1.0; }
bool is_vector(tuple v) { return v.w == 0.0; }