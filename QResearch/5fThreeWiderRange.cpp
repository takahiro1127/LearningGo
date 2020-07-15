#include <iostream>
#include <Eigen/Dense>
#include <fstream>
using std::ofstream;
using std::endl;
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
Vector3d base(-3, -3, -3);
Vector3d endPoint(3, 3, 3);
//各行列の大きさはdot^3
//各次元の点の数
int dot = 13;
int all_index = dot * dot * dot;
MatrixXd H(all_index, all_index), Base(all_index, all_index), X(all_index, all_index), XY(all_index, all_index);
VectorXd psi(all_index), g(all_index), phi(all_index), gPrev(all_index);
double h = 0.5;
double rh = 2;
int main() {
	for (int i = 0; i < all_index; i++){
		Vector3d position = indexToCoordinate(i);
		X(i, i) = position.dot(position);
		Base(i, i) = 7.5;
		// XY(i, i) = (position[0] - 1) * (position[0] - 1) * (position[1] - 1) * (position[1] - 1) * (position[1] - 1) * (position[1] - 1);
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
		// psi[i] = answer(position);
		psi[i] = 0.000001 * random()/32767;
		//初期値に正しい値をぶっこんで一回だけ回せばいい
	}
	std::string s = "output_";
	s += std::to_string(0);
	s += "_xy.csv";
	std::ofstream ofs(s);
	ofs<< "x,y,z,psi"<< endl;
	for (int i = all_index- 1; i >= 0; i--) {
		Vector3d position = indexToCoordinate(i);
		if (position[0] == 3 || position[0] == -3 || position[1] == 3 || position[1] == -3 || position[2] == 3 || position[2] == -3) {
			continue;
		}
		// ofs<< position[0] << "," << position[1] << "," << position[2] << "," << psi[i]/(sqrt(K) * (answer(position))) << "" << endl;
		ofs<< position[0] << "," << position[1] << "," << position[2] << "," << psi[i] << "" << endl;
	}
	std::string k = "output_";
	k += "answer";
	k += "_xy.csv";
	std::ofstream oks(k);
	oks<< "x,y,z,psi"<< endl;
	for (int i = all_index- 1; i >= 0; i--) {
		Vector3d position = indexToCoordinate(i);
		if (position[0] == 3 || position[0] == -3 || position[1] == 3 || position[1] == -3 || position[2] == 3 || position[2] == -3) {
			continue;
		}
		// ofs<< position[0] << "," << position[1] << "," << position[2] << "," << psi[i]/(sqrt(K) * (answer(position))) << "" << endl;
		oks<< position[0] << "," << position[1] << "," << position[2] << "," << answer(position) << "" << endl;
	}
	H = X * 0.5 + Base * 0.5 * rh * rh;
	// H = X * 0.5 + Base * 0.5 * rh * rh;
	g = deltaFunction();
	phi = g;
	std::cout << 0 << " : " << originFunction() << std::endl;
	for (int i = 1;  i < 1; i++) {
		psi = psi + alpha() * phi;
		gPrev = g;
		g = deltaFunction();
		phi = g + beta() * phi;
		// phi = g;
		if (i <=10 || i == 18 || i == 20 || i == 30 || i == 50 || i  % 100 == 0) {
			std::cout << i << " : " << originFunction() << std::endl;
		}
		// if (i <=10 || i == 18 || i == 20 || i == 30 || i == 50 || i  % 100 == 0) {
		// // if (i == 5000 || i == 4000 || i == 2000 || i == 3000) {
		// 	std::string s = "output_";
		// 	s += std::to_string(i);
		// 	s += "_jj.csv";
		// 	std::ofstream ofs(s);
		// 	ofs<< "x,y,z,psi"<< endl;
		// 	double S;
		// 	S = psi.dot(psi) * h * h * h;//積分はこれと確認ずみ
		// 	for (int i = all_index- 1; i >= 0; i--) {
		// 		Vector3d position = indexToCoordinate(i);
		// 		if (position[0] == 3 || position[0] == -3 || position[1] == 3 || position[1] == -3 || position[2] == 3 || position[2] == -3) {
		// 			continue;
		// 		}
		// 		// ofs<< position[0] << "," << position[1] << "," << position[2] << "," << psi[i]/(sqrt(S) * (answer(position))) << "" << endl;
		// 		ofs<< position[0] << "," << position[1] << "," << position[2] << "," << psi[i] << "" << endl;
		// 	}
		// }
	}
	// double S;
	// S = psi.dot(psi) * h * h * h;//積分はこれと確認ずみ
	// // std::cout << << std::endl;
	// for (int i = all_index- 1; i >= 0; i--) {
	// 	Vector3d position = indexToCoordinate(i);
	// 	if (position[0] == 0 && abs(position[1]) != 3 && abs(position[2]) != 3) {
	// 		std::cout << "position: " << position[0] << ", "<< position[1] << ", " << position[2]  << " 比率: " <<  psi[i]/(sqrt(S) * (answer(position))) << std::endl;
	// 	}
	// }

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
