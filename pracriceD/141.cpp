#include<iostream>
#include<queue>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    priority_queue<int> que;
    for (int i = 0; i < n; i++) {
        int Ai;
        cin >> Ai;
        que.push(Ai);
    }
    for (int i = 0; i < m; i++) {
        int k;
        k = que.top();
        que.pop();
        que.push(k/2);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += que.top();
        que.pop();
    }
    cout << sum << endl;
}

//nこの商品を買う
//i番目の商品の値段はAiえん
//m枚の商品券を持っていて
//Ai円の商品に対してk枚使った時はAi/2^k円で買うことができる
//この時割り算は小数点以下切り捨て
//最小で何円で買えるか

//A[i]をpriority queueに値段が高い順で入れていく
//popしてA[i]/2したあとpushする
//m回繰り返したあと合計する