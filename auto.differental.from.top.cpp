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
        // このNodeのinputとなったNodeと、dこのNode/d係数とした微分の値のペア
        stack<Node*> inputs;
        stack<ld> differentials;


        Node(ld val) {
            output = val;
            dfdg = 1;
        }

        void setAsInput(Node &input,ld dNoodedinput) {
            inputs.push(&input);
            differentials.push(dNoodedinput);
        }

        // 基本演算
        friend const Node operator + (Node left, Node right) {
            Node result = Node(left.output + right.output);
            result.setAsInput(left, 1);
            result.setAsInput(right, 1);
            return result;
        }

        friend const Node operator * (Node &left, Node &right) {
            Node result = Node(left.output * right.output);
            result.setAsInput(left, right.output);
            result.setAsInput(right, left.output);
            return result;
        }

        // 一般的な関数
        friend const Node exp(Node index) {
            Node result = Node(exp(index.output));
            result.setAsInput(index, result.output);
            return result;
        }

        // 参照渡しをしたいので、overrideする。
        friend const Node operator + (ld left, Node &right) {
            Node leftNode = Node(left);
            return leftNode + right;
        }

        friend const Node operator + (Node &left, ld right) {
            Node rightNode = Node(left);
            return left + rightNode;
        }

        friend const Node operator * (ld left, Node &right) {
            Node leftNode = Node(left);
            return leftNode * right;
        }

        friend const Node operator * (Node &left, ld right) {
            Node rightNode = Node(left);
            return left * rightNode;
        }
};

int main() {
    cout << "(e^x + 5x)の微分で確認" << endl;
    ld x_val = 1;
    Node x = Node(x_val);
    // (exp(x) + 5 * x).backword();
    cout << (exp(x) + 5.0 * x).output << endl;
    cout << exp(x_val) + 5.0 * x_val << endl;
}