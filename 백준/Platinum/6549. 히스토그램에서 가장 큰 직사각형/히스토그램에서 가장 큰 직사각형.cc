/*
- 시간제한 : 1초 = 1억
- 메모리제한 : 256MB = 0.6억개 int
- 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000)
  그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다.
  모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

  - O(N^2) = 10^10 시간 초과
  - O(NlogN) = 10^5 * 5 가능.
*/

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

constexpr int MX = 100000;
int h[MX];
long long ans;

int n, num;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while ((cin >> n) && (n != 0))
    {
        stack<int> s;
        ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        for (int i = 0; i < n; i++)
        {
            num = h[i];

            while (!s.empty() && h[s.top()] > num)
            {
                int height = h[s.top()];
                s.pop();
                int width = (s.empty()) ? i : (i - s.top() - 1);
                ans = (ans < (long long)width * height) ? (long long) width * height : ans;
            }

            s.emplace(i);
        }

        while (!s.empty())
        {
            int height = h[s.top()];
            s.pop();
            int width = (s.empty()) ? n : (n - s.top() - 1);
            ans = (ans < (long long)width * height) ? (long long) width * height : ans;
        }

        cout << ans << '\n';
    }

    return 0;
}