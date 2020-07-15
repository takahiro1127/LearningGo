// Pページの本
// iページ目にはaiが書かれている
// 全ての内容を網羅するために必要なページ数
// 18881
// →2
#include<iostream>
#include<set>//重複を許さない平衡二分木
#include<map>
using namespace std;
int P;
set<int> binary_tree;
int main() {
    int a[P];
    cin >> P;
    for (int i = 0; i < P; i++) {
        cin >> a[i];
        binary_tree.insert(a[i]);
    }
    int unique, count, result, start, end;
    start = 0;
    end = 0;
    count = 0;
    unique = binary_tree.size();
    map<int, int> readed;
    for (;end < P; end++) {
        if (readed[a[end]] == 0) {
            count++;
        }
        readed[a[end]] += 1;
        for (;count == unique; start++) {
            if (result > end - start) {
                result = end - start;
            }
        }
    }
}
