#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef long double ld;
#define PI 3.141592653589793
// ボトムアップ型の自動微分
class Node {
    public:
        ld val;
        ld dval;
        Node(ld xval = 0, ld dxval = 0) {
            val = xval;
            dval = dxval;
        }

        void select_as_delta() {
            dval = 1.0;
        }

    // 四則演算
        friend const Node operator + (Node rhs, Node lhs) {
            return Node(rhs.val + lhs.val, rhs.dval + lhs.dval);
        }

        friend const Node operator - (Node rhs, Node lhs) {
            return Node(rhs.val - lhs.val, rhs.dval - lhs.dval);
        }

        friend const Node operator * (Node rhs, Node lhs) {
            return Node(rhs.val * lhs.val, rhs.dval * lhs.val + rhs.val * lhs.dval);
        }

        friend const Node operator / (Node hx, Node gx) {
            return Node(hx.val / gx.val, (hx.dval * gx.val - hx.val * gx.dval) / (gx.val  * gx.val));
        }
        // 一般的な関数
        // *などとの処理順番の問題があるため、powは^にしない
        friend const Node pow (Node rhs, Node lhs) {
            return Node(pow(rhs.val, lhs.val), pow(rhs.val, lhs.val) * lhs.dval * log(rhs.val) + pow(rhs.val, lhs.val - 1) * lhs.val * rhs.dval);
        }

        friend const Node sin(Node child) {
            return Node(sin(child.val), child.dval * cos(child.val));
        }

        friend const Node cos(Node child) {
            return Node(cos(child.val), child.dval * -1 * sin(child.val));
        }

        friend const Node tan(Node child) {
            return Node(tan(child.val), (child.dval / cos(child.val)) / cos(child.val));
        }

        friend const Node exp(Node child) {
            ld child_exp = exp(child.val);
            return Node(child_exp, child.dval * child_exp);
        }

        friend const Node log(Node child) {
            return Node(log(child.val), child.dval / child.val);
        }

        friend const Node log(ld base, Node child) {
            return Node(log(child.val) / log(base), child.dval /(child.val * log(base)));
        }

        friend Node sqrt(Node child) {
            return Node(sqrt(child.val), child.dval / (sqrt(child.val) * 2));
        }
};

int main() {
    cout << "自動微分のテスト" << endl;
    cout << "sin(x)" << endl;
    ld x_val = PI / 2;
    Node x(x_val);
    x.select_as_delta();
    cout << "(sin(x)' = cos(x)  x => pi/2 : cos(pi/2) = 0 : 微分の値 => " << sin(x).dval << endl;
    ld x_val_2 = PI;
    Node x_2(x_val_2);
    x_2.select_as_delta();
    cout << "(sin(x)' = cos(x)  x => pi : cos(pi) = -1 : 微分の値 => " << sin(x_2).dval << endl;
    cout << "cos(x)" << endl;
    x_val = PI / 3;
    Node x_3(x_val);
    x_3.select_as_delta();
    cout << "(cos(x)' = sin(x) "<< sqrt(3)/2 << " : 微分の値 => " << cos(x_3).dval << endl;
    x_val_2 = 2 * PI / 3;
    Node x_4(x_val_2);
    x_4.select_as_delta();
    cout << "(cos(x)' = sin(x)  x => 2pi/3 : sin(2pi/3) = "<< -1 * sqrt(3)/2 << " : 微分の値 => " << cos(x_4).dval << endl;
    cout << "cos^4(3x - 2)" << endl;
    x_val = 1;
    Node x_5(x_val);
    x_5.select_as_delta();
    cout << "(cos^4(3x - 2)' = -12cos^3(3x - 2)sin(3x - 2) "<< -12 * pow(cos(1), 3) * sin(1) << " : 微分の値 => " << pow(cos((3 * x_5) - 2),  4).dval << endl;
    x_val_2 = 5;
    Node x_6(x_val_2);
    x_6.select_as_delta();
    cout << "(cos^4(3x - 2)' = -12cos^3(3x - 2)sin(3x - 2) "<< -12 * pow(cos(13), 3) * sin(13) << " : 微分の値 => " << pow(cos((3 * x_6) - 2), 4).dval << endl;
    cout << "log(log(log(log(5x))))" << endl;
    x_val = 1;
    Node x_7(x_val);
    x_7.select_as_delta();
    cout << "log(log(log(log(5x))))' = 1/(xlog5x *  log(log5x) * log(log(log(5x))))"<< 1/(log(5) *  log(log(5)) * log(log(log(5)))) << " : 微分の値 => " << log(log(log(log(5 * x_7)))).dval << endl;
    x_val_2 = 5;
    Node x_8(x_val_2);
    x_8.select_as_delta();
    cout << "log(log(log(log(5x))))' = -12cos^3(3x - 2)sin(3x - 2) "<< 1/(5 * log(25) *  log(log(25)) * log(log(log(25)))) << " : 微分の値 => " << log(log(log(log(5 * x_8)))).dval << endl;
    cout << "(2x^2  - 7x + 3) / (2x - 1)" << endl;
    x_val = 4;
    Node x_9(x_val);
    x_9.select_as_delta();
    cout << "(2x^2  - 7x + 3) / (2x - 1)' " << 1 << " : 微分の値 => " << ((2 * pow(x_9, 2)  - 7 * x_9 + 3) / (2 * x_9 - 1)).dval << endl;
    x_val = 5;
    Node x_10(x_val);
    x_10.select_as_delta();
    cout << "(2x^2  - 7x + 3) / (2x - 1)' " << 1 << " : 微分の値 => " << ((2 * pow(x_10, 2)  - 7 * x_10 + 3) / (2 * x_10 - 1)).dval << endl;
    cout << "^3√4-x^2" << endl;
    x_val = 1;
    Node x_11(x_val);
    x_11.select_as_delta();
    cout << "(- 2x / (3 * ^3√(4-x^3)^2))  = " << -2 * x_val / (3 * pow(4 - pow(x_val, 2), 2.0/3)) << " : 微分の値 => " << pow(4 - pow(x_11, 2), 1.0/3).dval << endl;
    x_val = 0.5;
    Node x_12(x_val);
    x_12.select_as_delta();
    cout << "(- 2x / (3 * ^3√(4-x^3)^2))  = " << -2 * x_val / (3 * pow(4 - pow(x_val, 2), 2.0/3)) << " : 微分の値 => " << pow(4 - pow(x_12, 2), 1.0/3).dval << endl;
    cout << "(2x^2 + 2x + 1)/√x" << endl;
    x_val = 10;
    Node x_13(x_val);
    x_13.select_as_delta();
    cout << "((6x^2+2x-1)/2x√x)  = " << (6 * pow(x_val, 2) + 2 * x_val - 1)/(2 * x_val * sqrt(x_val)) << " : 微分の値 => " << ((2 * pow(x_13, 2) + 2 * x_13 + 1) / sqrt(x_13)).dval << endl;
    cout << "e^3x" << endl;
    x_val = 11;
    Node x_14(x_val);
    x_14.select_as_delta();
    cout << "(3 * e^3x)  = " << 3 * exp(3 * x_val) << " : 微分の値 => " << (exp(3 * x_14)).dval << endl;
    cout << "tan(4x - 1)^3" << endl;
    x_val = 6;
    Node x_15(x_val);
    x_15.select_as_delta();
    cout << "(12 * tan(4x - 1)^2)/cos(4x - 1)^2  = " << (12 * pow(tan(4 * x_val - 1), 2) / pow(cos(4 * x_val - 1), 2)) << " : 微分の値 => " << pow(tan(4 * x_15 - 1), 3).dval << endl;
    cout << "log_2 x" << endl;
    x_val = 6;
    Node x_16(x_val);
    x_16.select_as_delta();
    cout << "1/(log(2) * x)  = " << 1/(log(2) * x_val) << " : 微分の値 => " << log(2, x_16).dval << endl;
    x_val = 1;
    Node x_17(x_val);
    x_17.select_as_delta();
    cout << "実験" << " : 微分の値 => " << (exp(5.0 * x_17 * x_17) + 5.0 * x_17 + x_17 * x_17 * x_17).dval << endl;
}