#include<iostream>
using namespace std;
int n;
long int x[100000];
long int d[100000];
long int sum;
int main() {
    cin >> n;
    cin >> x[0];
    for (int i = 1; i < n; i++) {
        cin >> x[i];
        d[i] = x[i] - x[i - 1];
    }
    sum = x[n] - x[0];
    int score = sum;
    for (int i = 1; i < n - 1; i++) {
        score += sum + (sum - d[0]); //一回　二回かぶり
        score += sum + 2 * (sum - d[1] - d[0]) + (sum - d[n - 1] - d[0]); //3買いかぶり
        score += sum + 2 * (sum - d[1] - d[0]) + (sum - d[n - 1] - d[0]); //4買いかぶり

        score += sum + k * (sum - d[0] - d[1] - .... d[k - 1])
    }
}
//youtubeで答え確認済み
//動的計画方でいけるかも
