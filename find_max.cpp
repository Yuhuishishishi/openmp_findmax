#include <cstdio>
#include <omp.h>
#include "find_max.h"
#include <queue>

Interval::Interval(double a, double b) {
	start = a;
	end = b;
}

double Interval::getStart() {
	return start;
}

double Interval::getEnd() {
	return end;
}

std::vector<Interval> Interval::split() {
	// return two sub interval
	std::vector<Interval> sub_intvls;
	double mid = (start + end) / 2.0;
	Interval intvl1(start, mid);
	Interval intvl2(mid, end);
	sub_intvls.push_back(intvl1);
	sub_intvls.push_back(intvl2);
	return sub_intvls;
}

bool Interval::exist_max(double(*func)(double), double eps, double s, double current_max_val) {
	double possible_max_val = (func(start) + func(end) + s*(end - start)) / 2.0;
	if (possible_max_val < current_max_val + eps)
		return false;
	else
		return true;
}

Interval get_task(std::queue<Interval> task_queue, omp_lock_t *queue_lock) {
	// get on task from the queue
	// set lock
	omp_set_lock(queue_lock);
	// pull one task
	Interval task = task_queue.front();
	// delete the current task from the queue
	task_queue.pop();
	// unset the lock
	omp_unset_lock(queue_lock);
	return task;
}

void insert_task(Interval task, std::queue<Interval> task_queue, omp_lock_t *queue_lock) {
	// insert one task to the queue
	// set lock
	omp_set_lock(queue_lock);
	task_queue.push(task);
	// unset the lock
	omp_unset_lock(queue_lock);
}
