#include <iostream>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
string s;
map<int, int> counter;
int main()
{
    cin >> s;
    counter.insert(make_pair(0, 0));
    counter.insert(make_pair(1, 0));
    counter.insert(make_pair(2, 0));
    int len = s.size();
    for (int i = 0; i < len; i++) {
        int k = stoi(s.substr(i, 1));
        counter[k % 3] += 1;
    }
    if (counter[1] > 0 || counter[2] > 0) {
        if (counter[0] == 0 && (((counter[1] == 1 || counter[1] == 2) && counter[2] == 0) || ((counter[2] == 1 || counter[2] == 2) && counter[1] == 0))) {
            cout << "-1" << endl;
        } else {
            int diff = max(counter[1], counter[2]) - min(counter[1], counter[2]);
            cout << min(diff % 3, max(counter[1] % 3, counter[2] % 3) - min(counter[1] % 3, counter[2] % 3)) << endl;
        }
    } else {
        cout << 0 << endl;
    }
}
