// MotorBallistics.cpp : Defines the entry point for the console application.
//Christopher Ross Simpson

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <Eigen/Dense>
//program specific
#include "geometry.h"
#include "StateOfElement.h"

using namespace Eigen;
using namespace std;

const double pi = 3.141592654;
const double a = 0.415;
const double n = 0.31;
const double rhop = 1840;//kg/m3


int main()
{
	double Ltot = 17.06;
	double t=0;
	double tnow;
	double dt = 0.1;
	double dx = 0.001;
	VectorXd W(int(Ltot / dx));
	W.setZero();

	//geometry
	double L1, Ltrans, L2;
	double rp1, rp2;
	L1 = 1097 / 100;//m
	Ltrans = 152 / 100;//m
	L2 = 457 / 100;//m
	rp1 = 20 / 100;//m
	rp2 = 64 / 100;//m

	VectorXd Ab(int(Ltot/dx));
	VectorXd Ap(int(Ltot / dx));
	//return the burning area
	geometry(Ab, Ap, W, dx);

	//pressure guess
	VectorXd pstag(int(Ltot / dx));
	VectorXd p(pstag.rows());
	VectorXd mdot(p.rows());
	VectorXd Mach(p.rows());
	VectorXd rb(p.rows());
	pstag[0] = 0.5e+06;
	p[0] = pstag[0];
	Mach[0] = 0;

	//run the loop
	double err = 1e-3;
	double limit = 100;
	double tf = 100;
	tnow = t;

	while(tnow<t)
	{
		stateofelement(pstag, p, mdot, Mach, rb, A);
		tnow = t + dt;
	}

    return 0;
}

