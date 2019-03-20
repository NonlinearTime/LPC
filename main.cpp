#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>

#include "lpc.h"

using namespace std;
using namespace Eigen;

int main() {
//    MatrixXd m(2, 2);
//    m(0, 0) = 1;
//    cout << m << endl;
//    ArrayXd a(2);
//    ArrayXXd b(2, 2);
//    VectorXd v;
//    MatrixXd x = m.row(0);
//    m.resize(3,3);
//    cout << m << endl;
//    v.resize(3);
//    v << 1,2,3;
//    cout << v[2] << endl;
//
//
//    a(0) = 2;
//    cout << b(3) << endl;
//    cout << v << endl;
//    int i = 0;
//    const int &p = 2;
//    i = p;
//    i = 3;
//    cout << i << endl;

//    MatrixXd m(2,2);
//    VectorXd v(2);
//    v(1) = 10;
//    m.row(0) = v;
//    cout << m << endl;

    lpc l;
    MatrixXd data(3,5);
    data << 3.1,2.2,3,4,5,
            4,6,7,8,9,
            11,12,13,14,15;
    l.setM(data);
    l.setP(2);
    l.predict();
    cout << l.getCoefficients() << endl;
    cout << l.getResiduals() << endl;


    return 0;
}

