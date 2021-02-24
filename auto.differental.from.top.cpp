#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <list>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef long double ld;
#define PI 3.141592653589793
// トップダウン型の自動微分
class Node {
    public:
        // 自分とfとの微分
        ld dfdg;
        // 自身の最終的な出力値
        ld output;
        int flag;
        int usedMaxFlag;
        // このNodeのinputとなったNodeと、dこのNode/d係数とした微分の値のペア
        // flagを参照したsearch機能を持つ、管理クラスを作るのもあり。
        vector<Node> inputs;
        vector<ld> differentials;
        map<int, ld> flagToDiff;

        Node(ld val = 1) {
            usedMaxFlag = 0;
            flag = 0;
            output = val;
            dfdg = 1;
        }

        void setDifferental() {
            flagToDiff = getDifferental();
        }

        map<int, ld> getDifferental(ld diff_from_top = 1) {
            dfdg = diff_from_top;
            //再起関数の終了条件
            //また、ここで初めて、flagToDiffに値がセットされる。
            if (flag != 0) {
                flagToDiff.insert(make_pair(flag, dfdg));
            }
            vector<Node>::iterator NodesIte = inputs.begin();
            vector<ld>::iterator DiffsIte = differentials.begin();
            for (; NodesIte != inputs.end() && DiffsIte != differentials.end(); NodesIte++, DiffsIte++) {
                mergeFlagToDiff(NodesIte->getDifferental(*DiffsIte * diff_from_top));
            }
            return flagToDiff;
        }

        void mergeFlagToDiff(map<int, ld> returnedFlagToDiff) {
            map<int, ld>::iterator flagAndDiff = returnedFlagToDiff.begin();
            for (; flagAndDiff != returnedFlagToDiff.end(); flagAndDiff++) {
                if (flagToDiff.find(flagAndDiff->first) == flagToDiff.end()) {
                    flagToDiff.insert(make_pair(flagAndDiff->first, flagAndDiff->second));
                } else {
                    flagToDiff[flagAndDiff->first] += flagAndDiff->second;
                }
            }
        }

        ld getDiff(Node node) {
            return flagToDiff[node.flag];
        }

        void setDiff(Node& node) {
            node.dfdg = getDiff(node);
        }

        //managerクラスなどで管理するのはあり。
        void setFlagAsVariable(int flag_number) {
            flag = flag_number;
            usedMaxFlag = max(flag_number, usedMaxFlag);
        }

        void setAsInput(Node input,ld dNoodedinput) {
            usedMaxFlag = max(usedMaxFlag, input.usedMaxFlag);
            inputs.push_back(input);
            differentials.push_back(dNoodedinput);
        }

        // 基本演算
        friend Node operator + (Node left, Node right) {
            Node result = Node(left.output + right.output);
            result.setAsInput(left, 1);
            result.setAsInput(right, 1);
            return result;
        }

        friend Node operator - (Node left, Node right) {
            Node result = Node(left.output - right.output);
            result.setAsInput(left, 1);
            result.setAsInput(right, -1);
            return result;
        }

        friend Node operator * (Node left, Node right) {
            Node result = Node(left.output * right.output);
            result.setAsInput(left, right.output);
            result.setAsInput(right, left.output);
            return result;
        }

        friend Node operator / (Node left, Node right) {
            Node result = Node(left.output / right.output);
            result.setAsInput(left, 1 / right.output);
            result.setAsInput(right, -1 * left.output / (right.output * right.output));
            return result;
        }

        // 一般的な関数
        friend Node exp(Node index) {
            Node result = Node(exp(index.output));
            result.setAsInput(index, result.output);
            return result;
        }

        friend Node sin(Node x) {
            Node result = Node(sin(x.output));
            result.setAsInput(x, cos(x.output));
            return result;
        }

        friend Node cos(Node x) {
            Node result = Node(cos(x.output));
            result.setAsInput(x, -1 * sin(x.output));
            return result;
        }

        friend Node tan(Node x) {
            Node result = Node(tan(x.output));
            result.setAsInput(x, 1 / (cos(x.output) * cos(x.output)));
            return result;
        }

        friend Node log(Node x) {
            Node result = Node(log(x.output));
            result.setAsInput(x, 1 / x.output);
            return result;
        }

        friend Node log(ld base, Node x) {
            Node result = Node(log(x.output) / log(base));
            result.setAsInput(x, 1 / (x.output * log(base)));
            return result;
        }

        friend Node pow (Node x, Node y) {
            Node result = Node(pow(x.output, y.output));
            result.setAsInput(x, y.output * pow(x.output, y.output - 1));
            result.setAsInput(y, result.output * log(x.output));
            return result;
        }

        friend Node sqrt(Node x) {
            Node result = Node(sqrt(x.output));
            result.setAsInput(x, 1 / (2 * result.output));
            return result;
        }
};

int main() {
//     st = exp(-1/2 * ファイ事情　*　dt) * exp(ファイ　* 乱数)
// st = exp(ファイ事情)　*so　*　exp(ファイ　*　randomの合計)
// dtの分散

// max(st1 + st2 + stn - kがストライク, 0) / df(割引係数)
// ↑
// これのボラティリテぃを
// 合計の乱数を与える。
    cout << "自動微分のテスト" << endl;
    cout << "sin(x)" << endl;
    ld x_val = PI / 2;
    Node x(x_val);
    x.setFlagAsVariable(1);
    Node f = sin(x);
    f.setDifferental();
    cout << "(sin(x)' = cos(x)  x => pi/2 : cos(pi/2) = 0 : 微分の値 => " << f.flagToDiff[1] << endl;
    x_val = PI;
    Node x_2(x_val);
    x_2.setFlagAsVariable(1);
    Node f_2 = sin(x_2);
    f_2.setDifferental();
    cout << "(sin(x)' = cos(x)  x => pi : cos(pi) = -1 : 微分の値 => " << f_2.flagToDiff[1] << endl;
    cout << "cos(x)" << endl;
    x_val = PI / 3;
    Node x_3(x_val);
    x_3.setFlagAsVariable(1);
    Node f_3 = cos(x_3);
    f_3.setDifferental();
    cout << "(cos(x)' = sin(x) "<< -1 * sqrt(3)/2 << " : 微分の値 => " << f_3.flagToDiff[1] << endl;
    x_val = 2 * PI / 3;
    Node x_4(x_val);
    x_4.setFlagAsVariable(1);
    Node f_4 = cos(x_4);
    f_4.setDifferental();
    cout << "(cos(x)' = sin(x)  x => 2pi/3 : sin(2pi/3) = "<< -1 * sqrt(3)/2 << " : 微分の値 => " << f_4.flagToDiff[1] << endl;
    cout << "cos^4(3x - 2)" << endl;
    x_val = 1;
    Node x_5(x_val);
    x_5.setFlagAsVariable(1);
    Node f_5 = pow(cos((3 * x_5) - 2),  4);
    f_5.setDifferental();
    cout << "(cos^4(3x - 2)' = -12cos^3(3x - 2)sin(3x - 2) "<< -12 * pow(cos(1), 3) * sin(1) << " : 微分の値 => " << f_5.flagToDiff[1] << endl;
    x_val = 5;
    Node x_6(x_val);
    x_6.setFlagAsVariable(1);
    Node f_6 = pow(cos((3 * x_6) - 2), 4);
    f_6.setDifferental();
    cout << "(cos^4(3x - 2)' = -12cos^3(3x - 2)sin(3x - 2) "<< -12 * pow(cos(13), 3) * sin(13) << " : 微分の値 => " << f_6.flagToDiff[1] << endl;
    cout << "log(log(log(log(5x))))" << endl;
    x_val = 1;
    Node x_7(x_val);
    x_7.setFlagAsVariable(1);
    Node f_7 = log(log(log(log(5 * x_7))));
    f_7.setDifferental();
    cout << "log(log(log(log(5x))))' = 1/(xlog5x *  log(log5x) * log(log(log(5x)))) "<< 1/(log(5) *  log(log(5)) * log(log(log(5)))) << " : 微分の値 => " << f_7.flagToDiff[1] << endl;
    x_val = 5;
    Node x_8(x_val);
    x_8.setFlagAsVariable(1);
    Node f_8 = log(log(log(log(5 * x_8))));
    f_8.setDifferental();
    cout << "log(log(log(log(5x))))' = 1/(xlog5x *  log(log5x) * log(log(log(5x))) "<< 1/(5 * log(25) *  log(log(25)) * log(log(log(25)))) << " : 微分の値 => " << f_8.flagToDiff[1] << endl;
    cout << "(2x^2  - 7x + 3) / (2x - 1)" << endl;
    x_val = 4;
    Node x_9(x_val);
    x_9.setFlagAsVariable(1);
    Node f_9 = ((2 * pow(x_9, 2)  - 7 * x_9 + 3) / (2 * x_9 - 1));
    f_9.setDifferental();
    cout << "(2x^2  - 7x + 3) / (2x - 1)' " << 1 << " : 微分の値 => " << f_9.flagToDiff[1] << endl;
    x_val = 5;
    Node x_10(x_val);
    x_10.setFlagAsVariable(1);
    Node f_10 = ((2 * pow(x_9, 2)  - 7 * x_9 + 3) / (2 * x_9 - 1));
    f_10.setDifferental();
    cout << "(2x^2  - 7x + 3) / (2x - 1)' " << 1 << " : 微分の値 => " << f_10.flagToDiff[1] << endl;
    cout << "^3√4-x^2" << endl;
    x_val = 1;
    Node x_11(x_val);
    x_11.setFlagAsVariable(1);
    Node f_11 = pow(4 - pow(x_11, 2), 1.0/3);
    f_11.setDifferental();
    cout << "(- 2x / (3 * ^3√(4-x^3)^2))  = " << -2 * x_val / (3 * pow(4 - pow(x_val, 2), 2.0/3)) << " : 微分の値 => " << f_11.flagToDiff[1] << endl;
    x_val = 0.5;
    Node x_12(x_val);
    x_12.setFlagAsVariable(1);
    Node f_12 = pow(4 - pow(x_12, 2), 1.0/3);
    f_12.setDifferental();
    cout << "(- 2x / (3 * ^3√(4-x^3)^2))  = " << -2 * x_val / (3 * pow(4 - pow(x_val, 2), 2.0/3)) << " : 微分の値 => " << f_12.flagToDiff[1] << endl;
    cout << "(2x^2 + 2x + 1)/√x" << endl;
    x_val = 10;
    Node x_13(x_val);
    x_13.setFlagAsVariable(1);
    Node f_13 = ((2 * pow(x_13, 2) + 2 * x_13 + 1) / sqrt(x_13));
    f_13.setDifferental();
    cout << "((6x^2+2x-1)/2x√x)  = " << (6 * pow(x_val, 2) + 2 * x_val - 1)/(2 * x_val * sqrt(x_val)) << " : 微分の値 => " << f_13.flagToDiff[1] << endl;
    // x_val = 10;
    // Node x_13(x_val);
    // x_13.select_as_delta();
    // cout << "((6x^2+2x-1)/2x√x)  = " << (6 * pow(x_val, 2) + 2 * x_val - 1)/(2 * x_val * sqrt(x_val)) << " : 微分の値 => " << ((2 * pow(x_13, 2) + 2 * x_13 + 1) / sqrt(x_13)).dval << endl;
    // cout << "e^3x" << endl;
    // x_val = 11;
    // Node x_14(x_val);
    // x_14.select_as_delta();
    // cout << "(3 * e^3x)  = " << 3 * exp(3 * x_val) << " : 微分の値 => " << (exp(3 * x_14)).dval << endl;
    // cout << "tan(4x - 1)^3" << endl;
    // x_val = 6;
    // Node x_15(x_val);
    // x_15.select_as_delta();
    // cout << "(12 * tan(4x - 1)^2)/cos(4x - 1)^2  = " << (12 * pow(tan(4 * x_val - 1), 2) / pow(cos(4 * x_val - 1), 2)) << " : 微分の値 => " << pow(tan(4 * x_15 - 1), 3).dval << endl;
    // cout << "log_2 x" << endl;
    // x_val = 6;
    // Node x_16(x_val);
    // x_16.select_as_delta();
    // cout << "1/(log(2) * x)  = " << 1/(log(2) * x_val) << " : 微分の値 => " << log(2, x_16).dval << endl;
    // x_val = 1;
    // Node x_17(x_val);
    // x_17.select_as_delta();
    // cout << "実験" << " : 微分の値 => " << (exp(5.0 * x_17 * x_17) + 5.0 * x_17 + x_17 * x_17 * x_17).dval << endl;
}