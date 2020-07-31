#include <iostream>
using namespace std;



/*
 * Complete the 'maxSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string maxSubstring(string s) {
    int n = s.length();
    string ans = s.substr(0, 1);;
    for (int i = 1; i < n; i++) {
        string last = s.substr(i, 1);
        if (ans < last) {
            ans = last;
        } else if (ans.substr(0, 1) == last) {
            string another_ans = maxSubstring(s.substr(i));
            if (ans + last > another_ans) {
                ans = ans + s.substr(i);
            } else if (ans < another_ans) {
                ans = another_ans;
                break;
            } else {
                ans += another_ans;
                break;
            }
        } else {
            ans += last;
        }
    }
    cout << "s is " << s << " and  ans is" << ans << "  " << endl;
    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    string result = maxSubstring(s);

    cout << result << "\n";
}
