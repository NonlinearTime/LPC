//
// Created by haines on 3/18/19.
//

#ifndef LPC_LPC_H
#define LPC_LPC_H

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class lpc {
    MatrixXd m, coefficients, residuals, autocorrelations;
    int p;

public:
    lpc(int p);

    lpc(const MatrixXd &m, const int &p);

    lpc();
    ~lpc();

    void get_coefficient();
    void get_residual();

    void cal_error();

    const MatrixXd &getM() const;
    void setM(const MatrixXd &m);

    int getP() const;
    void setP(int p);


private:
    const VectorXd &levinson_durbin(const VectorXd &r, const int &p);
    const VectorXd &auto_correlation(const VectorXd &r, const int &p);

protected:

};


#endif //LPC_LPC_H
