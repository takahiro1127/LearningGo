#include<iostream>
using namespace std;
typedef long long ll;
long int A, B;
ll gcd(ll , ll);
int main() {
    cin >> A >> B;
    long int X = A * B;
    cout << X / gcd(A, B) << endl;
}
ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}
