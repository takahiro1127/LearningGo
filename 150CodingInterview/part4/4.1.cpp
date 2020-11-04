#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 4.1
// グラフの実装
// 参照型で追加する事で、後からの変更に耐えれるようにしてある。
template <typename T>
class Node
{
public:
    T name;
    map<T, Node<T>& > children;
    bool visited;

    void addChild(Node<T>& node) {
        children.insert(make_pair(node.name, ref(node)));
    }

    bool directlyConnected(Node<T>& node) {
        return children.find(node.name) != children.end();
    }

    int countChildren()
    {
        return children.size();
    }
};
template <typename Y>
class Graph
{
public:
    void addNode(Node<Y>& node) {
        nodes.push_back(ref(node));
    }

    bool haveConnectionSearchDeep(Node<Y>& startNode, Node<Y>& endNode) {
        setAllNodeNonVisited();
        if (startNode.directlyConnected(endNode)) {
            return true;
        } else if (startNode.countChildren() == 0) {
            return false;
        } else {
            typename map<Y, Node<Y>& >::iterator child;
            bool result = false;
            for (child = startNode.children.begin(); child != startNode.children.end(); child++) {
                if (haveConnectionSearchDeep(child->second, endNode)) {
                    result = true;
                    break;
                };
            }
            return result;
        }
    }

    bool haveConnectionSearchWide(Node<Y>& startNode, Node<Y>& endNode) {
        setAllNodeNonVisited();
        queue<Node<Y> > nextNodes;
        nextNodes.push(startNode);
        bool result = startNode.name == endNode.name;
        for (;!nextNodes.empty() && !result;) {
            Node<Y> visitNode = nextNodes.front();
            nextNodes.pop();
            visitNode.visited = true;
            result = visitNode.directlyConnected(endNode);
            typename map<Y, Node<Y>& >::iterator child;
            for (child = visitNode.children.begin(); child != visitNode.children.end() && !result; child++) {
                if (!child->second.visited) {
                    nextNodes.push(child->second);
                }
            }
        }
        return result;
    }

    // bool haveConnectionSearchFromBothEnds(Node<Y>& startNode, Node<Y>& endNode) {
    //     setAllNodeNonVisited();
    //     queue<map<bool, Node<Y> > > nextNodes;
    //     // map nodeSearchFromStart
    //     nextNodes.push(make_pair(true, startNode));
    //     bool result = startNode.name == endNode.name;
    //     for (;!nextNodes.empty() && !result;) {
    //         Node<Y> visitNode = nextNodes.front();
    //         nextNodes.pop();
    //         visitNode.visited = true;
    //         result = visitNode.directlyConnected(endNode);
    //         typename map<Y, Node<Y>& >::iterator child;
    //         for (child = visitNode.children.begin(); child != visitNode.children.end() && !result; child++) {
    //             if (!child->second.visited) {
    //                 nextNodes.push(child->second);
    //             }
    //         }
    //     }
    //     return result;
    // }

private:
    vector<Node<Y> > nodes;
    void setAllNodeNonVisited() {
        int n = nodes.size();
        for (int i = 0; i < n; i++)
        {
            nodes[i].visited = false;
        }
    }
};
int main() {
    // 1→2, 3, 4→5
    // の探索を行ってみる
    Node<int> one;
    one.name = 1;
    Node<int> two;
    two.name = 2;
    Node<int> three;
    three.name = 3;
    Node<int> four;
    four.name = 4;
    Node<int> five;
    five.name = 5;
    one.addChild(two);
    one.addChild(three);
    one.addChild(four);
    Graph<int> graph;
    graph.addNode(one);
    graph.addNode(two);
    graph.addNode(three);
    graph.addNode(four);
    graph.addNode(five);
    four.addChild(five);

    if (graph.haveConnectionSearchDeep(one, five)) {
        cout << "つながってる" << endl;
    } else {
        cout << "つながっていない" << endl;
    }

    if (graph.haveConnectionSearchWide(one, five)) {
        cout << "つながってる" << endl;
    } else {
        cout << "つながっていない" << endl;
    }
}