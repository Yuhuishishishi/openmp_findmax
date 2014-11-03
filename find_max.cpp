#include <cstdio>
#include <omp.h>
#include "find_max.h"

Interval::Interval(double a, double b) {
	start = a;
	end = b;
}

Interval* Interval::split(Interval *two_intervals) {
	// return two sub interval
	double mid = (start + end) / 2.0;
	Interval intvl1(start, mid);
	Interval intvl2(mid, end);
	two_intervals[0] = intvl1;
	two_intervals[1] = intvl2;
	return two_intervals;
}

bool Interval::exist_max(double(*func)(double), double eps, double s, double current_max_val) {
	double possible_max_val = (func(start) + func(end) + s*(end - start)) / 2.0;
	if (possible_max_val < current_max_val + eps)
		return false;
	else
		return true;
}



void max_func(double (*func)(double), double a, double b, double eps, double s, double *max_x, double *max_val) {
	double current_max_val;
	if (func(a) > func(b))
		current_max_val = func(a);
	else
		current_max_val = func(b);
	Interval new_intvl(a, b);
	printf("%d\n", new_intvl.exist_max(func, eps, s, current_max_val));

	
}


