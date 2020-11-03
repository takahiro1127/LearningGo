#include <iostream>
#include <vector>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int> > s)
{
    int count[9];
    int cost = 0;
    for (int i = 0; i < 9; i++)
    {
        count[i] = 0;
    }
    // 後ろから走査していき
    // 2こ以上ある場合は一つ前に移動、0個の場合は一番近い下方向の数字で二つ以上ある物から受け取る
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            count[s[i][j] - 1]++;
        }
    }
    for (int i = 8; i >= 0; i--)
    {
        if (count[i] >= 2)
        {
            // cout << i << endl;
            count[i - 1] += count[i] - 1;
            cost += count[i] - 1;
            count[i] = 1;
        }
        else if (count[i] == 0)
        {
            // cout << i << endl;
            for (int j = i - 1; j >= 0; j--)
            {
                if (count[j] >= 1)
                {
                    count[i] = 1;
                    count[j]--;
                    cost += (i - j);
                    break;
                }
            }
        }
    }
    return cost;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int> > s(3);
    for (int i = 0; i < 3; i++)
    {
        s[i].resize(3);

        for (int j = 0; j < 3; j++)
        {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);
    cout << result << endl;
    // fout << result << "\n";

    // fout.close();

    return 0;
}
