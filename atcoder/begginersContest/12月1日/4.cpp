#include<iostream>
using namespace std;
int n, s;
int search(int);
//3search(i) = 3search(i - 1) + 2search(i - 1);
//2search(i) = 2search(i - 1) + 1search(i - 1);
//1search(i) = 1search(i - 1) +
//って感じで行列使おうと思ってたけど、よくよく考えると、3search(i - 1) + 2search(i - 1)とかで重複削除できてないからボツだな
//search(i)を末尾に...
//もしかして尺取り法でいける？？

int main() {
    cin >> n >> s;
    search(4);
}

int search(int i) {

}
