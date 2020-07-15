#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
double targetFunction(Vector2f, Matrix2f, Matrix2f);
Vector2f dTargetFunction(Vector2f, Matrix2f, Matrix2f);
double getAlpha(Vector2f, Vector2f, Matrix2f, Matrix2f);

int main()
{
  Matrix2f A(2, 2), B(2, 2);
  A << 0, 1,
      2, 4;
  B << 0, 2,
      8, 9;

  Vector2f x, p, r;
  double alpha, beta;
  //xのinitial guessでこれは適当でいい。
  x << 1, 3;
  p = -1 * dTargetFunction(x, A, B);
  for (int i = 0; i < 5; i++) {
    //ループはおそらくこれでいい、ループの回数はn, n行列で最大n回
    alpha = getAlpha(x, p, A, B);
    x = x + alpha * p;
    r = -1 * dTargetFunction(x, A, B);
    p = r - beta * p;
  }
  std::cout << "x: " << x << std::endl;

  ColPivHouseholderQR<Matrix2f> dec(A);
  Vector2f answear = dec.solve(targetFunction(x, A, B) * B * x);
  std::cout << answear << std::endl;
}

double getAlpha(Vector2f x, Vector2f p, Matrix2f A, Matrix2f B)
{
  double a, b, c;
  a = p.dot(A * p) * p.dot(B * x) - p.dot(A * x) * p.dot(B * x);
  b = p.dot(A * p) * x.dot(B * x) - x.dot(A * x) * p.dot(B * p);
  c = p.dot(A * x) * x.dot(B * x) - x.dot(A * x) * p.dot(B * x);
  //これでいいのか怪しい。0以下じゃない場合エラー出すようにした方がいいのかなど、聞いた方がいい。
  return fmin((-1 * b - sqrt(b*b - 4 * a * c)) / 2 * a, (-1 * b + sqrt(b * b - 4 * a * c)) / 2 * a);
}

double targetFunction(Vector2f x, Matrix2f A, Matrix2f B)
{
  return (x.dot(A * x)) / x.dot(B * x);
}

Vector2f dTargetFunction(Vector2f x, Matrix2f A, Matrix2f B)
{
  return 2 * (A * x - targetFunction(x, A, B) * (B * x)) / x.dot(B * x);
}
