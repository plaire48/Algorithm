#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;
vector<int> v;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] < v[i])
        {
            s.pop();
        }

        cout << (s.empty() ? 0 : s.top() + 1) << ' ';
        s.emplace(i);
    }

    return 0;
}