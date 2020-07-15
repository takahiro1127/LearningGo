#include<iostream>
#include <math.h>
using namespace std;
int x;
bool IsPrime(int);
int main() {
    cin >> x;
    for (;;x++) {
        if (IsPrime(x)) {
            cout << x << endl;
            break;
        }
    }
}

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
