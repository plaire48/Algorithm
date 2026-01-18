/*
- 시간 제한 : 2초 = 2억
- 메모리 제한 : 128MB = 0.3억 int
n(0 ≤ n ≤ 10,000)개의 대학에서 강연 요청
각 대학에서는 d(1 ≤ d ≤ 10,000)일 안에 와서 강연하면 p(1 ≤ p ≤ 10,000)만큼의 강연료를 지불
-> 반성하는 그리디 = 일단 선택 후에 취소 가능. (힙)
-> nlogn + nlogn = 2* 10^5 log 5 =2 2log5 * 10^5 OK.
*/

#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int MX = 10000;
int n, ans;
pair<int, int> sd[MX];

priority_queue<int, vector<int>, greater<int>> min_pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, d;
        cin >> p >> d;

        sd[i] = {d, p};
    }

    sort(sd, sd + n, [](pair<int, int> a, pair<int, int> b)
         { return a.first < b.first; });

    for (int i = 0; i < n; i++)
    {
        min_pq.emplace(sd[i].second);
        while (min_pq.size() > sd[i].first)
        {
            min_pq.pop();
        }
    }

    while (!min_pq.empty())
    {
        ans += min_pq.top();
        min_pq.pop();
    }
    cout << ans;
    return 0;
}