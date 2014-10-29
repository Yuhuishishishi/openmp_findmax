#include <cstdio>
#include <cstdlib>
#include "find_max.h"
#include <omp.h>
#include <math.h>

double f(int); // function to evaluate

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
	printf("f(a) = %.4f, f(b) = %.4f\n", f(a), f(b));


	return 0;
}

double f(int x) {
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