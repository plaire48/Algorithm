/*
- 시간제한 : 1초
- 메모리제한 : 128MB = 0.3억 int

시간복잡도 : nlogn = 10^5 * 5 OK.
*/

#include <iostream>
#include <map>

using namespace std;

int n, m, level;
long long c;
map<int, int> tree;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> m;

        int left_level = -1;
        int right_level = -1;
        auto it = tree.upper_bound(m);
        if (it != tree.end())
        {
            right_level = it->second;
        }

        if (it != tree.begin())
        {
            left_level = (--it)->second;
        }

        if (left_level == -1 && right_level == -1)
        {
            level = 0;
        }
        else
        {
            level = (right_level < left_level) ? left_level : right_level;
        }

        tree.emplace(m, level + 1);
        c += level;

        cout << c << '\n';
    }
    return 0;
}