//
// Created by haines on 3/18/19.
//

#include "lpc.h"

lpc::lpc() {

}

lpc::~lpc() {

}

lpc::lpc(const MatrixXd &m, const int &p){
    this->m = new MatrixXd(m);
    this->p = p;
    this->rows = m.rows();
    this->cols = m.cols();
    this->coefficients = nullptr;
    this->residuals = nullptr;
}


void lpc::matrix_coefficient() {
    coefficients = new MatrixXd(rows, p + 1);
    VectorXd r;
    for (uint32_t i = 0 ; i < rows; ++i) {
        r = auto_correlation(m->row(i), p);
        coefficients->row(i) = levinson_durbin(r, p);
    }
}

void lpc::matrix_residual() {
    residuals = new MatrixXd(rows, cols - p);
    for (uint32_t i = 0; i < rows; ++i) {
        residuals->row(i) = cal_residuals(m->row(i), coefficients->row(i), p);
    }
}

void lpc::cal_error() {

}


int lpc::getP() const {
    return p;
}

void lpc::setP(int p) {
    lpc::p = p;
}

const MatrixXd &lpc::getM() const {
    return *m;
}

void lpc::setM(const MatrixXd &m) {
    if (this->m != nullptr) {
        delete this->m;
    }
    this->m = new MatrixXd(m);
    this->rows = m.rows();
    this->cols = m.cols();
}

const VectorXd &lpc::levinson_durbin(const VectorXd &r, const int &p) {
    assert(p <= r.size());

    uint32_t N = r.size();
    VectorXd *a = new VectorXd(p + 1);
    double_t e, tmp;
    double_t *a1, *a2, *a3;
    a1 = (double *)malloc(sizeof(double) * (p + 1));
    a2 = (double *)malloc(sizeof(double) * (p + 1));

    a1[1] = - r(1) / r(0);
    e = r(0) * (1 - a1[1] * a1[1]);

    for (uint32_t j = 2; j <= p ; ++j) {
        tmp = 0;
        for (uint32_t i = 1; i != j; ++i) {
            tmp += a1[i] * r(j - i);
        }
        a2[j] = -(r(j) + tmp) / e;

        for (uint32_t i = 1; i != j; ++i) {
            a2[i] = a1[i] + a2[j] * a1[j - i];
        }

        e = e * (1 - a2[j]*a2[j]);
        a3 = a1;
        a1 = a2;
        a2 = a3;
    }

    (*a)(0) = 1;

    for (uint32_t i = 1 ; i <= p ; ++i) {
        (*a)(i) = a1[i];
    }

    return *a;
}

const VectorXd &lpc::auto_correlation(const VectorXd &data, const int &p) {
    VectorXd *r = new VectorXd(p + 1);
    double_t t = 0;
    for (uint32_t i = 0; i <= p; ++i) {
        t = 0;
        for (uint32_t j = 0; j != data.size() - i; ++j) {
            t += data(j) * data(j + i);
        }
        (*r)(i) = t;
    }
    return *r;
}

const VectorXd &lpc::cal_residuals(const VectorXd &data, const VectorXd &a, const int &p) {
    VectorXd *r = new VectorXd(data.size() - p);
    for (uint32_t i = p;  i < data.size() ; ++i) {
        double_t t = 0;
        for (uint32_t j = 0; j < p; ++j) {
            t += data[p + j] * a(j + 1);
        }
        (*r)(i - p) = data(i) - t;
    }
    return *r;
}

const MatrixXd &lpc::getCoefficients() const {
    return *coefficients;
}

const MatrixXd &lpc::getResiduals() const {
    return *residuals;
}


void lpc::predict() {
    matrix_coefficient();
    matrix_residual();
}




