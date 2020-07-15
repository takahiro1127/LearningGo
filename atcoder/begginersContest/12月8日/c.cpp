#include<iostream>
using namespace std;
int n;
int A[15][15];
int solve(int, int[]);
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 2;
        }
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            A[i][x - 1] = y;
        }
    }
    int b[n];
    for (int i = 0; i < n; i++) {
        b[i] = 2;
    }
    cout << solve(0, b) << endl;
}

int solve(int i, int b[]) {
    if (i == n - 1) {
        int count = 0;
        int check = 1;
        int never = 0;
        if (b[i] == 1 || b[i] == 2) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] != 2 || A[i][j] != b[j]) {
                    b[i] = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (b[j] == 2) {
                never = max(solve(j, b), never);
            }
            if (b[j] == 1) {
                count++;
            }
        }
        if (never != 0) {
            return never;
        }
        return count;
    }
    int lie = 0;
    if (b[i] == 2) {
        b[i] = 0;
        int bnext = 0;
        for (int j = i + 1; j < n; j++) {
            if (b[j] == 1) {
                bnext = 1;
                lie = solve(j, b);
                break;
            }
        }
        if (bnext == 0) {
            lie = solve(n - 1, b);
        }
    }
    b[i] = 1;
    for (int j = 0; j < n; j++) {
        if (A[i][j] == 2 || A[i][j] == b[j]) {
            continue;
        } else if (b[j] == 2) {
            b[j] = A[i][j];
        } else if (A[i][j] != b[j]) {
            return 0;
        }
    }
    int next = 0;
    for (int j = i + 1; j < n; j++) {
        if (b[j] == 1) {
            next = j;
            break;
        }
    }
    if (next == 0) {
        return max(solve(n - 1, b), lie);
    }
    return max(solve(next, b), lie);
}
