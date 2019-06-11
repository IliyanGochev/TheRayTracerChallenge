#include "TheRayTracerChallenge.h"
#include  "common.h"
struct color {
	real red, green, blue;
};

inline color Color(real red, real green, real blue) {
	return color{
		.red = red,
		.green = green,
		.blue = blue
	};
}

inline bool operator==(color const& l, color const& r) {
	return eps_equal(l.red, r.red) && 
			eps_equal(l.green, r.green) && 
			eps_equal(l.blue, r.blue);
}

inline color operator+(color const& c1, color const& c2) {
	return {
		.red	= c1.red		+ c2.red,
		.green	= c1.green	+ c2.green,
		.blue	= c1.blue		+ c2.blue
	};
}

inline color operator-(color const& c1, color const& c2) {
	return {
		.red	= c1.red		- c2.red,
		.green	= c1.green	- c2.green,
		.blue	= c1.blue		- c2.blue
	};
}

inline color operator*(color const& c, real const& s) {
	return {
	.red	= c.red		* s,
	.green	= c.green * s,
	.blue	= c.blue	* s 
	};
}

inline color operator*(color const& c1, color const& c2) {
	return color{
		.red	= c1.red		* c2.red,
		.green	= c1.green	* c2.green,
		.blue	= c1.blue		* c2.blue
	};
}