//
// Created by haines on 3/18/19.
//

#ifndef LPC_LPC_H
#define LPC_LPC_H

#include <iostream>
#include <Eigen/Dense>
#include <assert.h>

using namespace std;
using namespace Eigen;

class lpc {
    MatrixXd *m, *coefficients, *residuals;
public:
    const MatrixXd &getCoefficients() const;

    const MatrixXd &getResiduals() const;

private:
    int p;
    uint32_t rows, cols;

public:
    lpc(const MatrixXd &m, const int &p);

    lpc();
    ~lpc();


    void cal_error();

    const MatrixXd &getM() const;
    void setM(const MatrixXd &m);

    int getP() const;
    void setP(int p);

    void predict();


public:
    const VectorXd &levinson_durbin(const VectorXd &r, const int &p);
    const VectorXd &auto_correlation(const VectorXd &data, const int &p);
    const VectorXd &cal_residuals(const VectorXd &data, const VectorXd &a, const int &p);

    void matrix_coefficient();
    void matrix_residual();


protected:

};


#endif //LPC_LPC_H
