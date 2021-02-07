#include <iostream>
#include <vector>

using namespace std;

// 全探索を行うアルゴリズム
void makeCombination()

void main()
{
}

void rec(i) {
    if (i == n) {
        print(s)
    }
    rec(i + 1);
    S[i] = 1;
    rec(i + 1);
    S[i] = 0;
}

bool solve(int i, int m) {
    if (m == 0) {
        return true;
    } else if (i == n) {
        return false;
    }
    return solve(i + 1, m) || solve(i + 1, m - A[i]);
}