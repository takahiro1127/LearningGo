#include <iostream>
#include <Eigen/Dense>
#include <fstream>
using namespace Eigen;
using std::ofstream;
using std::endl;
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
		Base(i, i) = 6;
		for (int j = 0; j < 3; j++) {
			if (nextIndex(position, j) < all_index) {
				Base(i, nextIndex(position, j)) = -1;
			}
			if (prevIndex(position, j) >= 0) {
				Base(i, prevIndex(position, j)) = -1;
			}
		}

		psi[i] = answer(position);
		//初期値に正しい値をぶっこんで一回だけ回せばいい
	}
	H = X * 0.5 + Base * 0.5 * rh * rh;
	g = deltaFunction();
	phi = g;
	for (int i = 1;  i < 31; i++) {
		psi = psi + alpha() * phi;
		gPrev = g;
		g = deltaFunction();
		phi = g + beta() * phi;
		if (i == 5 || i == 20 || i == 30) {
			for (int i = all_index- 1; i >= 0; i--) {
				std::string s = "output_";
				s += i;
				s += ".csv";
				ofstream ofs(s);
				ofs<< "x, y, z, psi\n"<< endl;
				Vector3d position = indexToCoordinate(i);
				ofs<< position[0] << ", " << position[1] << ", " << position[2] << ", " << psi[i] << ", \n" << endl;
			}
		}
	}
	double S;
	S = psi.dot(psi) * h * h * h;//積分はこれと確認ずみ
	// std::cout << << std::endl;
	for (int i = all_index- 1; i >= 0; i--) {
		Vector3d position = indexToCoordinate(i);
		std::cout << "position: " << position[0] << ", "<< position[1] << ", " << position[2]  << " 比率: " <<  psi[i]/(sqrt(S) * (answer(position))) << std::endl;
	}
}
//三次元の座標をどのように一次元配列に割り振っていくか
//[(0,0,0) -> (1, 1, 1)]で0.1刻みだと考える
//x0.1に対し、yが10通りさらにそのそれぞれに10通りのzが考えられる
int coordinateToIndex(Vector3d position) {
	return  ((rh * position[0] - rh * base[0]) * dot * dot + (rh * position[1] - rh * base[1]) * dot + rh * position[2] - rh * base[2]);
}
Vector3d indexToCoordinate(int index) {
	double x, y, z;
	x = index / (dot * dot);
	y = index / dot - x * dot;
	z = index - y * dot - x * dot * dot;
	Vector3d cordinate(x * h, y * h, z * h);
	return cordinate + base;
}
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
