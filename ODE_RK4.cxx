/*
 * ODE_RK4.cxx
 *
 *  Created on: Mar 14, 2019
 *      Author: Shahzaib Malik
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

double dydx
(double y, double x) {

	return (3*exp(-x)-0.4*y); //ODE to solve (https://www.youtube.com/watch?v=AT7Olelic8U&t=162s)
}

//RK 4 formulas
double RK4(double y, double x, double x0, double h) {

	double k1, k2,k3,k4;
	int n;
	n = (x - x0) / h;

	for (int i = 1; i <= n; i++) {


		k1 = dydx(y, x0);
		k2 = dydx(y+0.5*(k1*h), x0+0.5*h);
		k3 = dydx(y+0.5*(k2*h),x0+0.5*h);
		k4 = dydx(y+(k3*h),x0+h);

		x0 = x0 + h;
		y = y + (h/6)*(k1+(2*k2)+(2*k3)+k4);
	}

	return y;
}

//main function
int main(int argc, char *argv[]) {

	double x0, y, h, x;
	x0 = 0;
	y = 5;
	h = 1.5;
	x = 3.0;

	cout << "The value of y is: " << RK4(y,x, x0, h) << endl;
}


