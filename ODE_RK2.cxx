/*
 * ODE_RK2.cxx
 *
 *  Created on: Mar 13, 2019
 *      Author: sm2016
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <memory>
#include <stdlib.h>
using namespace std;

double dydt(double y, double t) {

	return (y * pow(t, 3) - 1.5 * y); //ODE to solve (https://www.youtube.com/watch?v=6PwS9YlZa3k)
}

//RK 2 formulas
double RK2(double y, double t, double t0, double h) {

	double k1, k2;
	int n;
	n = (t - t0) / h;

	for (int i = 1; i <= n; i++) {

		//h2=h/2; //just test as in streamline-tracking code
		k1 = dydt(y, t0);
		k2 = dydt(y + 0.5 * (k1 * h), t0 + 0.5 * h);

		t0 = t0 + h;
		y = y + (k2 * h);
	}

	return y;
}

//main function
int main(int argc, char *argv[]) {

	double t0, y, h, t;
	t0 = 0;
	y = 1;
	h = 0.5;
	t = 1;

	cout << "The value of y is: " << RK2(y,t, t0, h) << endl;
}
