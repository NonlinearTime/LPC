//
// Created by haines on 3/18/19.
//

#include "lpc.h"

lpc::lpc() {

}
lpc::~lpc() {

}

lpc::lpc(const MatrixXd &m, const int &p) : m(m), p(p) {}


void lpc::get_coefficient() {

}

void lpc::get_residual() {

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
    return m;
}

void lpc::setM(const MatrixXd &m) {
    lpc::m = m;
}

const VectorXd &lpc::levinson_durbin(const VectorXd &r, const int &p) {
    uint32_t N = r.size();
    

    return VectorXd(2);
}

const VectorXd &lpc::auto_correlation(const VectorXd &data, const int &p) {
    VectorXd r(p);
    double_t t = 0;
    for (uint32_t i = 0; i != p; ++i) {
        t = 0;
        for (uint32_t j = 0; j != p - i; ++i) {
            t += data(j) * data(j + i);
        }
        r(i) = t;
    }
    return r;
}



