#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
// https://blog.foresta.me/posts/enumerate_all_pattern/
// 順列の全列挙

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}


int main() {

    vector<int> nums(5);
    iota(nums.begin(), nums.end(), 0);

    do {
        printVector(nums);
    } while (next_permutation(nums.begin(), nums.end()));


    return 0;
}