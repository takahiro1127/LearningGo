#include<iostream>
using namespace std;
int n;
int ans = 0;
int l[2000];
int maxIndexSearch(int, int);
bool maxC(int, int);
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l, l + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int max = maxIndexSearch(i, j);
            ans += max - j;//多分あってる
        }
    }
    cout << ans << endl;
}

bool maxC(int x, int length) {
    return l[x] < length;
    //x > jなので l[j] - l[i] < l[j]は必ず満たす
}

int maxIndexSearch(int i, int j) {//l[i] + l[j] > l[k]を満たす最小のkを見つける
    int langth = l[i] + l[j];
    int max = n - 1;
    int min = j+1;//l[i] + l[j] < l[j]はありえないから
    int mid;
    for (int m = 0; m < 30; m++) {
        mid = (max + min) / 2;
        if (maxC(mid, length)) {
            min = mid;//lengthより短い場合は元上にあげれるよって事
        } else {
            max = mid;
        }
    }
    return mid;
}




//ここに残っているのはmin系のやつ
//重複を防ぐためにjより大きいkでl[k] > l[j] - l[i]を満たす物を探していたが、そもそもl[j] > l[j] - l[i]を満たすので探索する必要がない
// bool minC(int x, int length) {
//     return l[x] > length;
// }

// int minIndexSearch(int i, j) {//length(=l[j] - l[i])よりも大きい最小のindexを知りたい
//     int max = j;//ここで、必ずl[j] > l[j] - l[i]を満たすため
//     int min = 0;
//     int mid;
//     for (int m = 0; m < 10; m++) {
//         mid = (min + max) / 2;
//         if (minC(mid, l[j] - l[i])) {
//             max = mid;
//         } else {
//             min = mid;
//         }
//     }

// }

//互いに区別できるn本の棒iばんめの長さはli
//三角形は何通り作ることができるか
//ここで、三角形であるためにはa < b + c && b < c + a && c < a + bがなりてっている必要がある。
//二つの辺を選んで、二分探索で残り一つの辺を求め、見つける。
//ここで、被りをうまく避ける必要がある

//方針はOK!!解答と全く同じ方針でできてる！！