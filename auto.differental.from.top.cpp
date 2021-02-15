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
            result.setAsInput(x, -sin(x.output));
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

        friend const Node pow (Node x, Node y) {
            Node result = Node(pow(x.output, y.output));
            result.setAsInput(x, y.output * pow(x.output, y.output - 1));
            result.setAsInput(y, result.output * log(x.output));
            return result;
            return Node(pow(rhs.val, lhs.val), pow(rhs.val, lhs.val) * lhs.dval * log(rhs.val) + pow(rhs.val, lhs.val - 1) * lhs.val * rhs.dval);
        }

        friend Node sqrt(Node x) {
            Node result = Node(sqrt(x.output));
            result.setAsInput(x, -1 / (2 * result.output));
            return result;
        }
};

int main() {
    //グローバルに、変数のアドレスを持ったstackを持たせて、最終的に、値渡しで作ったdifferentalを再代入する。
    //式の終わりを明示するfinishというメソッドを作成するように
    cout << "(e^x + 5x)の微分で確認" << endl;
    ld x_val = 1;
    Node x = Node(x_val);
    x.setFlagAsVariable(1);
    Node f = (exp(5.0 * x * x) + 5.0 * x + x * x * x);
    cout << f.output << endl;
    f.setDifferental();
    map<int, ld>::iterator flag_ite = f.flagToDiff.begin();
    for (; flag_ite != f.flagToDiff.end(); flag_ite++) {
        cout << flag_ite->first << " : " << flag_ite->second << endl;
    }
    cout << exp(5.0 * x_val * x_val) + 5.0 * x_val + x_val * x_val * x_val<< endl;
}