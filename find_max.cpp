#include <cstdio>
#include <omp.h>
#include "find_max.h"

void max_func(double (*func)(double), double a, double b, double eps, double s, double *max_x, double *max_val) {
	double current_max_val;
	if (func(a) > func(b))
		current_max_val = func(a);
	else
		current_max_val = func(b);
	printf("%d\n", if_exist_max(func, a, b, eps, s, current_max_val));

	
}

bool if_exist_max(double (*func)(double), double c, double d, double eps, double s, double current_max_val) {
	double possible_max_val = (func(c) + func(d) + s*(d - c)) / 2.0;
	if (possible_max_val < current_max_val + eps)
		return false;
	else
		return true;
}