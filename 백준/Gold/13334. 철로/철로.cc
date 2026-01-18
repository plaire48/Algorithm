/*
- 시간제한 : 1초 = 10^8
- 메모리제한 : 512MB = 1.2억 int
입력은 표준입력을 사용한다. 첫 번째 줄에 사람 수를 나타내는 양의 정수 n (1 ≤ n ≤ 100,000)이 주어진다.
다음 n개의 각 줄에 정수 쌍 (hi, oi)가 주어진다.
여기서 hi와 oi는 −100,000,000이상, 100,000,000이하의 서로 다른 정수이다.
마지막 줄에, 철로의 길이를 나타내는 정수 d (1 ≤ d ≤ 200,000,000)가 주어진다.
nlogn
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>> max_pq;

int n, d, sp, ep;
int ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int h, o;
        cin >> h >> o;

        if (h > o)
            swap(h, o);
        v.emplace_back(h, o);
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
         { if(a.first == b.first) return a.first > b.first;
            return a.first > b.first; });

    cin >> d;
    for (const auto &e : v)
    {
        if (e.second - e.first > d)
            continue;

        max_pq.emplace(e.second);

        while (!max_pq.empty() && max_pq.top() - e.first > d)
        {
            max_pq.pop();
        }

        ans = max(ans, (int)max_pq.size());
    }

    cout << ans;

    return 0;
};