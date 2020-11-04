#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 4.2
// 二分探索木の実装
// 自己参照をすることでnullを表現
template <typename T>
class BinaryTree
{
public:
    BinaryTree<T>* right;
    BinaryTree<T>* left;
    BinaryTree<T>* parent;
    T value;

    BinaryTree(T newValue) {
        value = newValue;
        parent = this;
        right = this;
        left = this;
    }

    BinaryTree<T>& search(T searchValue) {
        if (value == searchValue) {
            return *this;
        } else if (searchValue > value) {
            if (right == this) {
                return NULL;
            } else {
                return (*right).search(searchValue);
            }
        } else if (searchValue < value) {
            if (left == this) {
                return NULL;
            } else {
                return (*left).search(searchValue);
            }
        }
    }

    void push(T newValue) {
        if (newValue > value) {
            if (right == this) {
                BinaryTree rightBinaryTree(newValue);
                rightBinaryTree.parent = this;
                right = &rightBinaryTree;
            } else {
                (*right).push(newValue);
            }
        } else if (newValue < value) {
            if (left == this) {
                BinaryTree leftBinaryTree(newValue);
                leftBinaryTree.parent = this;
                left = &leftBinaryTree;
            } else {
                (*left).push(newValue);
            }
        }
    }

    BinaryTree<T>& getBigger() {
        return *right;
    }

    BinaryTree<T>& getSmaller() {
        return *left;
    }
};


int main() {
    BinaryTree<int> bt(12);
    bt.push(3);
    bt.push(4);
    bt.push(14);
    bt.push(23);
    bt.push(2);
    cout << (*(*(bt.right)).right).value << endl;
}