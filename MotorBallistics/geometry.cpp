#include "geometry.h"

//specific to AJ10A
void geometry(VectorXd &A, VectorXd &Ap, VectorXd W, double dx) {
	double L1, Ltrans, L2;
	double rp1, rp2;
	double aftA;
	double headA;
	double newA;
	double newport;

	//initial values
	L1 = 1097 / 100;//m
	Ltrans = 152 / 100;//m
	L2 = 457 / 100;//m
	rp1 = 20 / 100;//m
	rp2 = 64 / 100;//m

   //outer values
	double d = 1.58;//m

	//area
	//TODO: correct the iteration procedure for putting area where it should be
	//TODO: Fix the radius/height for the transition.
	for (int i = 0; i < A.rows(); i++)
	{
		newA = 2 * pi*(rp1 + W[i])*dx;
		newport = (pi / 4)*(rp1 + W[i]);
		if ((rp1 + W[i])>d)
		{
			newA = 0;
		}
		A[i] = newA;

		newA = 2 * pi*(rp2 + W[i])*dx;
		newport = (pi / 4)*(rp2 + W[i]);
		if ((rp2 + W[i])>d)
		{
			newA = 0;
		}
		A[i] = newA;


		aftA = 2 * pi*(rp2 + W[i])*dx;
		headA = pi*(rp1 + W[i])*pow(pow(rp1 + W[i], 2) + pow(dx, 2), 0.5);
		if ((rp1 + W[i])>d)
		{
			headA = 0;
		}
		if ((rp2 + W[i])>d)
		{
			aftA = 0;
		}
		newA = aftA + headA;
		A[i] = newA;
	}
}