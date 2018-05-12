#pragma once
#ifndef STATEOFELEMENT_H
#define STATEOFELEMENT_H
#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

double pi;
double a;
double n;
double rhop;

void stateofelement(VectorXd &pstag, 
					VectorXd &p, 
					VectorXd &mdot, 
					VectorXd &Mach, 
					VectorXd &rb,
					VectorXd Ab,
					VectorXd Ap);
#endif // STATEOFELEMENT_H

