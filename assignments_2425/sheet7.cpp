#include <armadillo>
#include <cassert>

template<int n>
void vmult(arma::vec &res, arma::vec &v) {
  assert(n * n == v.n_rows);
  int constexpr c = (n + 1) * (n + 1);
  res = 4 * v;
  for (int i = 0; i < n * n; ++i) {
    if (i >= n) {
      res[i] -= v[i - n];
    }
    if (i < n * (n - 1)) {
      res[i] -= v[i + n];
    }
    if (i % n != 0) {
      res[i] -= v[i - 1];
    }
    if (i % n !=  n - 1) {
      res[i] -= v[i + 1];
    }
  }

  res *= (n + 1) * (n + 1);
  return;
}

int main(int argc, char **argv) {
  // Meaningless example on how to use the function
  constexpr int n = 3;
  arma::vec test(n * n, arma::fill::ones);
  arma::vec res;
  vmult<n>(res, test);

  return 0;
}
