// 長さがそれぞれLiであるようなN本の紐がある。
// これらの紐を切って同じ長さの紐をk本作るときの最長の長さ
// 少数点2桁までで切り捨て
// ex)N=4, k=11 l = {8.02 7.43 4.57 4.39} => 3= 2.0
// 各紐から4, 3, 2, 2の11本

#include<iostream>
using namespace std;

bool C(double);
void solve();
double n, k;
double l[100];
int main() {
    cin >> n >> k;
    for (int i = 0; i < 100; i++) {
        if (i < n) {
            cin >> l[i];
        } else {
            l[i] = 0;
        }
    }
    //連続した数における二分探索
    solve();
}

// 
bool C(double x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += l[i]/x;
    }
    return (sum >= k);
}

// 二分探索
void solve() {
    double max, min;
    max = 100;
    min = 0;
    // 何回二分探索を行うか
    int max_search_count = 5;
    for (int i = 0; i < max_search_count; i++) {
        if (C((min+max)/2)) {
            // Cの決め方は人それぞれ
            min = (max + min)/2;
        } else {
            max = (max + min)/2;
        }
    }
    // 二分探索の答え
    cout << (min+max)/2 << endl;
}

