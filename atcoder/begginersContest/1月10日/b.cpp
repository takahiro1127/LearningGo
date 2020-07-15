#include<iostream>
using namespace std;
int n;
string s;
int main() {
    cin >> n;
    cin >> s;
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            count++;
        }
    }
    cout << count << endl;
}
