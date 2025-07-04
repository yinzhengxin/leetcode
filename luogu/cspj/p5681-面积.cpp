#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long S1 = a * a;
    long long S2 = b * c;
    if (S1 > S2)
    {
        cout << "Alice";
    }
    else
    {
        cout << "Bob";
    }
}