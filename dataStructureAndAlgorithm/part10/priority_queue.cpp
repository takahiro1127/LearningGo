#include <iostream>
#include <queue>

using namespace std;
void main()
{
    priority_queue<int> PQ;
    PQ.push(1);
    PQ.push(8);
    PQ.push(2);
    PQ.push(10);
    cout << PQ.top() << endl;
    PQ.pop()
    PQ.push(30);
    cout << PQ.top() << endl;
}