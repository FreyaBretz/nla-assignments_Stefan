#include <iostream>
#include <array>
#include <armadillo>

std::array<double, 2> Compute_givens(double a, double b) {
  std::array<double, 2> res;
  if(b == 0) {
    res = {1, 0};
  } else {
    if (std::abs(b) < std::abs(a)) {
      double tau  = - a/b;
      res.at(1) = 1 / std::sqrt(1 + tau * tau);
      res.at(0) = tau * res.at(1);
    } else {
      double tau  = - b/a;
      res.at(0) = 1 / std::sqrt(1 + tau * tau);
      res.at(1) = tau * res.at(0);
    }
  }
  return res;
}

void Apply_givens_left(arma::vec &x, double c, double s, int j, int k) {
  double alpha = x(j);
  double beta = x(k);
  x(j) = c * alpha - s * beta;
  x(k) = s * alpha + c * beta;
}

void Apply_givens_right(arma::vec &x, double c, double s, int j, int k) {
  double alpha = x(j);
  double beta = x(k);
  x(j) = c * alpha - s * beta;
  x(k) = s * alpha + c * beta;
}
int main(int argc, char** argv) {
  arma::vec x = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::array<double, 2> givens_parameter;
  for(int i = x.size()-2; i >= 0; --i) {
    givens_parameter = Compute_givens(x(i), x(i + 1));
    std::cout << "parameter at step " << i << ": " << givens_parameter.at(0) << ", " << givens_parameter.at(1) << std::endl;
    Apply_givens_left(x, givens_parameter.at(0), givens_parameter.at(1), i, i + 1);
    std::cout << "x at step " << i << ": " << x << std::endl;
  }


  for(int n = 2; n < 20; ++n) {
    x = arma::randu(n);
    std::cout << "Problem of size " << n << std::endl;
    for(int i = x.size()-2; i >= 0; --i) {
      givens_parameter = Compute_givens(x(i), x(i + 1));
      std::cout << "parameter at step " << i << ": " << givens_parameter.at(0) << ", " << givens_parameter.at(1) << std::endl;
      Apply_givens_left(x, givens_parameter.at(0), givens_parameter.at(1), i, i + 1);
      std::cout << "x at step " << i << ": " << x << std::endl;
    }
  }
  return 0;
}
