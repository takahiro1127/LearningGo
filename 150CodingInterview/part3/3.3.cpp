#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 3.3
template <typename T>
class SetOfStack
{
public:
    SetOfStack()
    {
        stack<T> smallStack;
        bigStack.push_back(smallStack);
        stackCount = 0;
    }

    void push(T item)
    {
        if (isLimit())
        {
            addStack();
        }
        bigStack[stackCount].push(item);
    }

    void pop()
    {
        // 例外を考えていない
        bigStack[stackCount].pop();
        if (isEmpty())
        {
            removeStack();
        }
    }

    T top()
    {
        // 例外を考えていない
        // if (bigStack.empty())
        // {
        //     bigStack.top()
        // }
        if (isEmpty(stackCount))
        {
            removeStack();
        }
        return bigStack[stackCount].top();
    }

    void popAt(int count)
    {
        bigStack[count].pop();
        if (isEmpty(count))
        {
            removeStack(count);
        }
    }

private:
    vector<stack<T>> bigStack;
    int stackCount;
    void addStack()
    {
        stack<T> smallStack;
        bigStack.push_back(smallStack);
        stackCount++;
    }

    // メンバ変数はデフォルト引数に使えないため、オーバーロード
    void removeStack()
    {
        removeStack(stackCount);
    }

    void removeStack(int count)
    {
        bigStack.erase(bigStack.begin() + count);
        stackCount--;
    }

    bool isLimit()
    {
        return isLimit(stackCount);
    }

    bool isLimit(int count)
    {
        return bigStack[count].size() > 10;
    }

    bool isEmpty()
    {
        return isEmpty(stackCount);
    }

    bool isEmpty(int count)
    {
        return bigStack[count].empty();
    }
};

int main()
{
    SetOfStack<int> st;
    for (int i = 0; i < 100; i++)
    {
        st.push(i);
    }

    for (int i = 0; i < 10; i++)
    {
        st.popAt(i);
    }

    for (int i = 0; i < 30; i++)
    {
        cout << st.top() << endl;
        st.pop();
        st.pop();
    }
}