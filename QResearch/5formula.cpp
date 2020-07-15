#include<iostream>
#include<Eigen/Dense>
using namespace Eigen;
double originFunction();
VectorXd deltaFunction();
double alpha();
double beta();
//todo -5から5でやってるけど-10から10
//todo -5から5でもっとメッシにやってみる

MatrixXd H(100, 100), Base(100, 100), X(100, 100);
VectorXd psi(100), g(100), phi(100), gPrev(100);
double h, j, rh;
int main() {
	j = -5.0;
	h = 0.1;
	rh = 10;
	for (int i = 0; i < 100; i++) {
		if (i > 75 || i < 25) {
			psi[i] = 0;
		} else {
			psi[i] = cos(j*2/3.2)/2;
			// psi[i] = pow(2.71828, (-0.5 * j * j));
		}
		Base(i, i) = 5/2;
		if (i > 1) {
			Base(i, i - 2)= 1/12;
		}
		if (i < 98) {
			Base(i, i + 2)= 1/12;
		}
		if (i != 0) {
			Base(i, i - 1)= -4/3;
		}
		if (i != 99) {
			Base(i, i + 1) = -4/3;
		}
		X(i, i) = j * j;
		j += h;
	}
	H = X * 0.5 + Base * 0.5 * rh * rh;
	// psi = VectorXd::Zero(100);  //適当な点を中心としたがうしあん-aからaまでの三角関数-2.5から2.5とか
	//グラフの形で出してみる
	//hを小さくする
	//hを固定で3テント5てんの公式で比較
	//二つ目の極小値求める
	//協約勾配の方向からpsi0に比例している部分を消していく
	//psi2を求める場合は0-1の両方に直行
	g = deltaFunction();
	phi = g;
	std::cout << 0 << " : " << originFunction() * 3 << std::endl;
	// std::cout << phi << std::endl;
	for (int i = 1;  i < 1; i++) {
		psi = psi + alpha() * phi;
		gPrev = g;
		g = deltaFunction();
		phi = g + beta() * phi;
		// phi = g;
		// std::cout << originFunction() << std::endl;
		if (i <= 10 || i % 10 == 0) {
			std::cout << i << " : " << originFunction() * 3 << std::endl;
		}
	}

	//積分
	// double S;
	// for (int i = 0; i < 100; i++) {
	// 	S += abs(psi[i]) * abs(psi[i]) * h;
	// }
	// j = -5.0;
	// for (int i = 0; i < 100; i++) {
	// 	std::cout << "x : "<< j << "/ e^-((x^2)/2): " << pow(2.71828, (-0.5 * j * j))/sqrt(sqrt(3.141592)) << "/ psi : " << psi[i]/sqrt(S) << "/ 比率: " <<  psi[i]/(sqrt(S) * (pow(2.71828, (-0.5 * j * j))/sqrt(sqrt(3.141592)))) << std::endl;
	// 	j += h;
	// }
	//積分した値が1nなるように
	//hは使わないf
	// EigenSolver<MatrixXd> es(H);
	// std::cout << es.eigenvalues() << std::endl;
}

double originFunction() {
	//❷の式　これを極小化するpsiが求める固有ベクトルであり、その時のこの式の値が対応する固有値になっている
	return (psi.dot(H * psi)) / psi.dot(psi);
}

VectorXd deltaFunction() {
	return 2 * (originFunction() * psi - (H * psi)) / psi.dot(psi);
}

double alpha() {
	double a = (phi.dot(H * phi)) * phi.dot(psi) - ((phi).dot(H * psi)) * phi.dot(phi);
	double b = (phi.dot(H * phi)) * psi.dot(psi) - ((psi).dot(H * psi)) * phi.dot(phi);
	double c = (phi.dot(H * psi)) * psi.dot(psi) - ((psi).dot(H * psi)) * phi.dot(psi);
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	// return phi.dot(g) / g.dot(H * phi);//収束までにこっちだったらどれくらい言ってるか
}

double beta() {//betaとalphaがほとんど関与できていない
	// return 0;
	return (g.dot(g) / gPrev.dot(gPrev));
}
