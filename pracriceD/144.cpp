#include<iostream>
#include <cmath>
using namespace std;
int a, b, x;
double s;
bool triangle;
bool c(double);
double triangleL(double);
double trapezoidL(double);
double search();
int main() {
    cin >> a >> b >> x;
    s = x / a;
    triangle = b * a / 2 > s;
    cout << search() << endl;
}
//溢れる場合false, 溢れない場合trueで返す
bool c(double angle) {
    double l;
    if (triangle) {
        l = triangleL(angle);
    } else {
        l = trapezoidL(angle);
    }
    return l <= b;
}

double triangleL(double angle) {
    return sqrt(s * 2 / tan(angle));
}

double trapezoidL(double angle) {
    return (s / a + a / tan(angle)) / 2;
}


double search() {
    double max = 90;
    double min = 0;
    double mid;
    for (int i = 0; i < 20; i++) {
        mid = (max + min) / 2;
        if (c(mid)) {
            min = mid;
        } else {
            max = mid;
        }
    }
    return mid;
}
//底がacmの正方形　高さがbcm
//xcm^3を入れ、正方形の一つの辺を軸に傾ける
//水を溢れさせない最大の角度

//自分の方針
//二分探索で角度を求める

//細かい方針は抜きにするとあっている
//わざわざ二分探索しなくても、l = bとおけば答えを一意に決めることができる段階まできているので、そっちで出力する方がよかった。