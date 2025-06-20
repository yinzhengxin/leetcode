#include <iostream>

using namespace std;

int p5660()
{
    string s;
    cin >> s;
    int num = 0;
    if (s.size() != 8)
        return 0;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (*it == '1')
        {
            num++;
        }
    }
    cout << num;
    return 0;
}

int main()
{
    return p5660();
}