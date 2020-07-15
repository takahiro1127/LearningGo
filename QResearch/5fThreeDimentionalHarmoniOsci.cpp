#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
int coordinateToIndex(Vector3d);
int nextIndex(Vector3d, int);
int prevIndex(Vector3d, int);
double originFunction();
VectorXd deltaFunction();
double alpha();
double beta();
double answer(Vector3d);
double oneDimentionAnswer(double);
Vector3d indexToCoordinate(int);
//基準となるvector
Vector3d base(-0.5, -0.5, -0.5);
Vector3d endPoint(0.5, 0.5, 0.5);
//各行列の大きさはdot^3
//各次元の点の数
int dot = 11;
int all_index = dot * dot * dot;
MatrixXd H(all_index, all_index), Base(all_index, all_index), X(all_index, all_index);
VectorXd psi(all_index), g(all_index), phi(all_index), gPrev(all_index);
double h = 0.1;
double rh = 10;
int main() {
	for (int i = 0; i < all_index; i++){
		Vector3d position = indexToCoordinate(i);
		X(i, i) = position.dot(position);
		Base(i, i) = 7.5;
		for (int j = 0; j < 3; j++) {
			if (nextIndex(position, j) < all_index) {
				Base(i, nextIndex(position, j)) = -4/3;
			}
			if (prevIndex(position, j) >= 0) {
				Base(i, prevIndex(position, j)) = -4/3;
			}
			if (nextIndex(indexToCoordinate(nextIndex(position, j)), j) < all_index) {
				Base(i, nextIndex(indexToCoordinate(nextIndex(position, j)), j)) = 1/12;
			}
			if (prevIndex(indexToCoordinate(prevIndex(position, j)), j) >= 0) {
				Base(i, prevIndex(indexToCoordinate(prevIndex(position, j)), j)) = 1/12;
			}
		}

		psi[i] = answer(position);
		//初期値に正しい値をぶっこんで一回だけ回せばいい
	}
	H = X * 0.5 + Base * 0.5 * rh * rh;
	g = deltaFunction();
	phi = g;
	for (int i = 1;  i < 100; i++) {
		psi = psi + alpha() * phi;
		gPrev = g;
		g = deltaFunction();
		phi = g + beta() * phi;
	}
	double S;
	S = psi.dot(psi) * h * h * h;//積分はこれと確認ずみ
	// std::cout << << std::endl;
	for (int i = all_index- 1; i >= 0; i--) {
		Vector3d position = indexToCoordinate(i);
		std::cout << "position: " << position[0] << ", "<< position[1] << ", " << position[2]  << " 比率: " <<  psi[i]/(sqrt(S) * (answer(position))) << std::endl;
	}

	// std::string sen = "-----------------------------------------------------------------------------------------";
	// std::cout << sen << std::endl;
	// Vector3d zex(-0.4, -0.5, -0.5);
	// std::cout << (zex[0] - base[0]) << " 掛け算　* " << dot * dot << "= " << (zex[0] - base[0]) * dot * dot * rh << std::endl;
	// std::cout <<  int(rh * (zex[0] - base[0]) * dot * dot + (zex[1] - base[1]) * dot + zex[2] - base[2]) << std::endl;
	// std::cout << coordinateToIndex(zex) << std::endl;
	// std::cout << nextIndex(zex, 0) << std::endl;
	// std::cout << nextIndex(zex, 1) << std::endl;
	// std::cout <<  nextIndex(zex, 2) << std::endl;
	// Vector3d ex(0, -0.2, -0.1);
	// std::cout << ex << std::endl;
	// std::cout << "x : " << indexToCoordinate(nextIndex(ex, 0)) << ", y : " <<  indexToCoordinate(nextIndex(ex, 1)) << ", z : " <<  indexToCoordinate(nextIndex(ex, 2)) << std::endl;
}
//三次元の座標をどのように一次元配列に割り振っていくか
//[(0,0,0) -> (1, 1, 1)]で0.1刻みだと考える
//x0.1に対し、yが10通りさらにそのそれぞれに10通りのzが考えられる
//todo もう一回確認後　確認印
int coordinateToIndex(Vector3d position) {
	return  ((rh * position[0] - rh * base[0]) * dot * dot + (rh * position[1] - rh * base[1]) * dot + rh * position[2] - rh * base[2]);
}
//todo もう一回確認後　確認印
Vector3d indexToCoordinate(int index) {
	double x, y, z;
	x = index / (dot * dot);
	y = index / dot - x * dot;
	z = index - y * dot - x * dot * dot;
	Vector3d cordinate(x * h, y * h, z * h);
	return cordinate + base;
}
//todo もう一回確認後　確認印
//direction:0→x 1→y 2→z
int nextIndex(Vector3d position, int direction) {
	if (direction == 0) {//11進数の引き算になっている
		return coordinateToIndex(position)  + dot * dot;
	} else if (direction == 1) {
		return coordinateToIndex(position)  + dot;
	} else if (direction  == 2) {
		return coordinateToIndex(position) + 1;
	}
	return 0;
}
//todo もう一回確認後　確認印

//direction:0→x 1→y 2→z
int prevIndex(Vector3d position, int direction) {
	if (direction == 0) {//11進数の引き算になっている
		return coordinateToIndex(position)  - dot * dot;
	} else if (direction == 1) {
		return coordinateToIndex(position)  - dot;
	} else if (direction  == 2) {
		return coordinateToIndex(position) - 1;
	}
	return 0;
}

double answer(Vector3d vect) {
	return oneDimentionAnswer(vect[0]) * oneDimentionAnswer(vect[1]) * oneDimentionAnswer(vect[2]);
}

double oneDimentionAnswer(double x) {
	return pow(2.71828, (-0.5 * x * x))/sqrt(sqrt(3.141592));
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
}

double beta() {
	return (g.dot(g) / gPrev.dot(gPrev));
}
