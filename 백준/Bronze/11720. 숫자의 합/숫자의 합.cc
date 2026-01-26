#include <iostream>
#include <string>
using namespace std;

int t, ans;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    cin >> s;

    for (const auto &e : s)
    {
        ans += (e - '0');
    }

    cout << ans;

    return 0;
}