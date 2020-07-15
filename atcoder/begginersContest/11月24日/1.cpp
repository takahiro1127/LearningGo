#include<iostream>
using namespace std;

int main() {
    string a;
    cin >> a;
    if (a == "SUN") {
        cout << 7 << endl;
    } else if (a == "MON") {
        cout << 6 << endl;
    } else if (a == "TUE") {
        cout << 5 << endl;
    } else if (a == "WED") {
        cout << 4 << endl;
    } else if (a == "THU") {
        cout << 3 << endl;
    } else if (a == "FRI") {
        cout << 2 << endl;
    } else if (a == "SAT") {
        cout << 1 << endl;
    }
}
