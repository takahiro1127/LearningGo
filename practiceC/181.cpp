#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

bool onSameLine(vector<int> point1, vector<int> point2, vector<int> point3) {
    // 標準化
    point2[0] -= point1[0];
    point2[1] -= point1[1];
    point3[0] -= point1[0];
    point3[1] -= point1[1];
    if ((point2[0] == 0 && point3[0] != 0) || point3[0] == 0 && point2[0] != 0) {
        return false;
    }
    if ((point2[1] == 0 && point3[1] != 0) || point3[1] == 0 && point2[1] != 0) {
        return false;
    }
    return point2[0] * point3[1] == point3[0] * point2[1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > points;
    for (int i = 0; i < n; i++) {
        vector<int> point;
        int x, y;
        cin >> x >> y;
        point.push_back(x);
        point.push_back(y);
        points.push_back(point);
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (onSameLine(points[i], points[j], points[k])) {
                    ans = true;
                    break;
                }
            }
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}