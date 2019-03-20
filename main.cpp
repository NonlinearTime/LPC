#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main() {
    MatrixXd m(2, 2);
    m(0, 0) = 1;
    ArrayXd a(2);
    ArrayXXd b(2, 2);
    VectorXd v;
    MatrixXd x = m.row(0);
    v.resize(3);
    v << 1,2,3;
    cout << v[2] << endl;


    a(0) = 2;
    cout << b(3) << endl;
    cout << v << endl;
    return 0;
}

