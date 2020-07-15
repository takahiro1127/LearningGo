#include<iostream>
#include<Eigen/Dense>
using namespace Eigen;

int main(){
  double a;
  Matrix2f A(2, 2);
  A << 3.4521, 0,
      0, 1.0;
  Vector2f b, r, r1, p, y, x;
  b << 0.5, 1.45642;
  //xは適当でいい
  x << 0, 1;
  //初期近似解に対する残渣
  r = b - A*x;
  p = r;
  for (int i = 0; i < 4; i++) {
    y = A * p;
    a = r.dot(r) / p.dot(y);
    // std::cout << a << std::endl;
    x = x + a * p;
    r1 = r - a * y;
    double B = r1.dot(r1) / r.dot(r);
    // std::cout << B << std::endl;
    p = r1 + B * p;
    r = r1;
  }
  std::cout << x << std::endl;

  ColPivHouseholderQR<Matrix2f> dec(A);
  Vector2f answear = dec.solve(b);
  std::cout << answear << std::endl;
}
