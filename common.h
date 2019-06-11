#pragma once
#define EPSILON 0.00001

template  <typename T>
bool eps_equal(T a, T b) {
	return (std::abs(a - b) < EPSILON) ? true : false;
}
