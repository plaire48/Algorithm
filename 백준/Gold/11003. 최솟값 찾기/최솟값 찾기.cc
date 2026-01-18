/*
- 시간제한 : 2.4초 (약 2.4억 -> 2.4 * 10^9)
- 메모리제한 : 512MB = 1.2억 int
- 첫째 줄에 N과 L이 주어진다. (1 ≤ L ≤ N ≤ 5,000,000)
  둘째 줄에는 N개의 수 Ai가 주어진다. (-10_9 ≤ Ai ≤ 10_9)
-> N = 5 * 10^6
   L = 5 * 10^6 -> 2.5 * 10^13 O(N*l)시간 초과
   -> O(N) 필요.
   슬라이딩 윈도우 방식 : 길이 N의 수열에서, 매번 K개씩 창문을 볼 때 그 안에서의 최댓값을 계속 출력하라
  */

#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int l, n, num;
deque<pair<int, int>> dq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        while (!dq.empty() && dq.back().second > num)
        {
            dq.pop_back();
        }

        dq.emplace_back(i, num);

        while (dq.front().first <= i - l)
        {
            dq.pop_front();
        }

        cout << dq.front().second << ' ';
    }

    return 0;
}
