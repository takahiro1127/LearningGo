#include <iostream>
#include <vector>
#include <map>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

template <typename T>
class DisjointSet
{
    public:
        map<T, int> ranks;
        map<T, T> parents;
        DisjointSet(){};

    void makeSet(T x) {
        parents[x] = x;
        ranks[x] = 0;
    }

    bool same(T x, T y) {
        return findSet(x) == findSet(y);
    }

    void unite(T x, T y) {
        link(findSet(x), findSet(y));
    }

    void link(T x, T y) {
        if (ranks[x] > ranks[y]) {
            parents[y] = x;
        } else {
            parents[x] = y;
            if (ranks[x] == ranks[y]) {
                ranks[y]++;
            }
        }
    }

    T findSet(T x) {
        if (x != parents[x]) {
            //再起的に深さを修正
            parents[x] = findSet(parents[x]);
        }
        return parents[x];
    }
};

int main() {
    DisjointSet<string> ds;
    ds.makeSet("aaa");
    ds.makeSet("abdb");
    ds.makeSet("dsgsd");
}