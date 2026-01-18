/*
- 시간제한 : 1초
- 메모리제한 : 256MB = 0.6억 int
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.
(-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
-> 단순한 좌표 정렬문제. nlogn = 10^5 * log5 OK.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.reserve(n);
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
         { return tie(a.second, a.first) < tie(b.second, b.first); });

    for (const auto &[x, y] : v)
    {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}