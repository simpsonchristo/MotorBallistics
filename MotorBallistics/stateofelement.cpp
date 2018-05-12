#include "StateOfElement.h"

void stateofelement(VectorXd &pstag,
	VectorXd &p,
	VectorXd &mdot,
	VectorXd &Mach,
	VectorXd &rb,
	VectorXd Ab,
	VectorXd Ap) {
	//start solving for each element
	for (int i = 0; i < mdot.rows(); i++)
	{
		rb[i] = a*pow(p[i], n);
		mdot[i] = rb[i]*rhop*Ab[i];
		if (i>0)
		{

		}
	}
}