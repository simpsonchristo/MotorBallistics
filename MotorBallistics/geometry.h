#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

double pi;

void geometry(VectorXd &A, VectorXd &Ap, VectorXd W, double dx);

#endif //GEOMETRY_H
