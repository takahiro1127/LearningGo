#include <iostream>
#include <map>

using namespace std;
void main()
{
    map<int, string> T;
    T['red'] = 32;
    T['blue'] = 993;

    T.insert(make_pair('purple', 1010));
}