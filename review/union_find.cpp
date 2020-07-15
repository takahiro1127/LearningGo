#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

class DisjointSet {
    public:
        vector<int> rank, p;
        DisjointSet() {}
        DisjointSet(int size) {//initializeのようなもの
            rank.resize(size, 0);
            p.resize(size, 0);
            rep(i, size) makeSet(i);//指定された数の要素数だけ、疎なDisjointSetを作っている。
        }

        void makeSet(int x) {
            p[x] = x;
            rank[x] = 0;
        }
        bool same(int x, int y) {
            return findSet(x) == findSet(y);
        }

        void unite(int x, int y) {
            ling(findSet(x), findSet(y));
        }

        void link(int x, int y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }

        int findSet(int x) {
            if (x != p[x]) {
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};
