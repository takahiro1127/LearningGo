#include<iostream>
#include<Eigen/Dense>
#include <vector>
using namespace std;
using namespace Eigen;
typedef unsigned long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
//問題条件
double r = 1.2;
double lambda = 0.5;
//todo ここのgammaとbetaはどんな値がいいのかよくわかっていない
double gamma = 0.2;
double beta = 0.2;
//data importによって変化
ll N;
ll TimeCount;
MatrixXd covariance;
VectorXd exReturn, x, epsilons, deltas;
vector<VectorXd> data;

void modifyBasedOnData() {

}
void train() {
    //todo 現状bを考慮できていないプログラムになっている。
    VectorXd y = exReturn * covariance;
    x = epsilons + (deltas - epsilons) / (VectorXd::Ones(N) + -1 * beta * (y - gamma));
    modifyBasedOnData();
}
vector ReadCsv() {
    vector<VectorXd> data;
    // data = getFromCsv();
    //具体的なロジックは一旦むし
    return data;
}
vector<VectorXd> getReturnRateFromPrice(vector importData) {
    //収益率の計算をする。
    return importData;
}
void importDate() {
    //readCsv and stock data as variables;
    //銘柄nの実現収益率を保持する
    //data = [[time = 0, 銘柄1の期待収益, 銘柄2の期待収益, ....銘柄nの期待収益], [time = 1]];
    data = getReturnRateFromPrice(ReadCsv());
    //init matrix and vectors;
    TimeCount = data.length();
    N = data[0].length();
    covariance = MatrixXd::Random(N, N);
    exReturn = VectorXd::Random(N);
    //各証券の上限と下限は[0, 1]にしている つまり上限下限の縛りはない
    epsilons = VectorXd::Zero(N);
    deltas = VectorXd::Ones(N);
    x = VectorXd::Random(N);
}
int main() {
    importData();
    rep(i, TimeCount) train();
    //todo 別fileに書き込むなどする。
    cout << x << endl;
}
