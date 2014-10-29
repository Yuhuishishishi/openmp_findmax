#include <cstdio>
#include <cstdlib>
#include "find_max.h"
#include <math.h>

double f(double); // function to evaluate

int main(int argc, char* argv[]) {
	printf("------------------Program start-----------------\n");
	// parse the arguments
	double a = 1, b = 1000, eps = 10e-12, s = 12;
	if (argc > 1) {
		a = atof(argv[1]);
		b = atof(argv[2]);
		eps = atof(argv[3]);
		s = atof(argv[4]);
	}

	double max_val, max_x; // variables to store the max values
	max_func(f, a, b, eps, s, &max_x, &max_val);
	return 0;
}

double f(double x) {
	double f_val = 0, inner_sum;
	for (int i = 100; i > 0; i--) {
		inner_sum = 0;
		for (int j = i; j > 0; j--) {
			inner_sum += pow(x + j, -3.1);
		}
		f_val += sin(x + inner_sum) / pow(1.2, i);
	}
	return f_val;
}