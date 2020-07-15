#include<iostream>
using namespace std;
int N;
int main() {
    cin >> N;
    int a[N], x[N];
    // xは降水量を表す配列
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    search(0);
}