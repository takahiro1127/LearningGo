#include<iostream>
using namespace std;
int N, Q;
int a[200000], b[200000], p[200000], x[200000];
int main() {
    cin >> N >> Q;
    //必ず、a[i]が親、b[i]が子となるように並べる
    //ただし、a[i], b[i]についてはその時点で打ち切っても木構造に矛盾が出ないようにしているとする。
    int keep, col;
    keep = 1;
    bool visit[200000];
    for (int i = 0; i < N - 1; i++) {
        cin >> a[i] >> b[i];
        if (a[i] == keep) {
            visit[b[i] - 1] = true;
        } else if (b[i] == keep) {
            swap(a[i], b[i]);
            visit[b[i] - 1] = true;
        } else {
            //todo!!!訪問済みフラグの管理を行えば、子供と親の判定は簡単になる。
            if (visit[b[i] - 1]) {
                swap(a[i], b[i]);
            }
            keep = a[i];
        }
    }
    int score[N];
    for (int i = 0; i < N; i++) {
        score[i] = 0;
    }
    for (int i = 0; i < Q; i++) {
        cin >> p[i] >> x[i];
        score[p[i] - 1] += x[i];
    }
    //ai, biは木の構造に矛盾がないように与えられている前提で考える→違った場合はそれようにsortする
    //頂点が1なので1から深さ優先探索でscoreを埋めていく
    //子の数は多くても、
    string s = "";
    for (int i = 0; i < N - 1; i++) {
        score[b[i] - 1] += score[a[i] - 1];
    }
    for (int i = 0; i < N; i++) {
        s += to_string(score[i]) + " ";
    }
    cout << s << endl;
}

//上から順番に足していって、一つ前の木の値+自分の値みたいな感じで考える

// 1~Nまでの番号がついたNこ頂点をもつ根付き木
// 木の頂点は頂点１でi番目の辺はaiとbiを結ぶ
// 各頂点にはカウンターがあって、初めは0
// 次の操作をQ回行う
//操作 j 頂点pjを根とする全ての頂点のカウンターの値にxjを足す