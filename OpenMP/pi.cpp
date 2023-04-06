#include "testing.h"
#include <omp.h>
#include <iostream>
#include <string>

using namespace std;

void displayValue(int ID, const char* valueName, double value) {
	cout << "ID " + to_string(ID) + " : " + valueName + " : " + to_string(value) + "\n";
}


#define NUMTHRDS 4

void pi() {
	float pi = 0.0;
	long numsteps = 15000000;
	double step = 1.0 / numsteps;
	//int nthrds;

	omp_set_num_threads(NUMTHRDS);

	// First Module Exercise Pi Computation
	/*
	#pragma omp parallel num_threads(NUMTHRDS)
	{
		int ID = omp_get_thread_num();
		int numthreads = omp_get_num_threads();
		if (!ID) nthrds = numthreads;
		int numrects = numsteps / numthreads;

		double sum = 0;
		for (int i = ID * numrects + 1; i < numrects * (ID+1); i++) {
			double x = (i + 1) * step;
			double y = 4.0 / (1.0 + x * x);
			sum += y * step;
		}

		displayValue(ID, "sum", sum);

		#pragma omp critical
		displayValue(ID, "PI", pi);
		pi += sum;
		displayValue(ID, "PI", pi);
	}*/

	
	#pragma omp parallel for reduction(+:pi) 
		for (int i = 0; i < numsteps; i++) {
			double x = (i + 1) * step;
			pi += (4.0 / (1.0 + x * x)) * step;
		}
	
	//cout << "nthrds : " + to_string(nthrds);

	cout << "\nAll done!\nThe sum is " + to_string(pi);
}

