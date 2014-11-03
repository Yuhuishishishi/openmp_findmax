void max_func(double (*func)(double), double a, double b, double eps, double s, double* max_x, double* max_val);

class Interval {
	double start, end;
public:
	Interval(double, double);
	Interval* split(Interval*); // return a ptr to 2 intervals
	bool exist_max(double(*func)(double), double eps, double s, double current_max_val);
};