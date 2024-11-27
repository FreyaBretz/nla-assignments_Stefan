#include <iostream>
#include <array>
#include <armadillo>

std::array<double, 2> Compute_givens(double a, double b) {

}

void Apply_givens_left(arma::vec &x, double c, double s, int j, int k) {
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
