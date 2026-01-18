/*
- 시간 제한 : 1초 = 1억
- 메모리 제한 : 256MB = 0.6억 int
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.
(-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

-> 대표적인 정렬 문제
O(nlogn)= 5 * 10^5 OK.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int n;

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

    sort(v.begin(), v.end());

    for (const auto &[e_x, e_y] : v)
    {
        cout << e_x << ' ' << e_y << '\n';
    }
}