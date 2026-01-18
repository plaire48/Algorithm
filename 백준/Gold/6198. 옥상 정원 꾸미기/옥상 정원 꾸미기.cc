/*
- 시간 제한 : 1초
- 메모리 제한 : 128MB

첫 번째 줄에 빌딩의 개수 N이 입력된다.(1 ≤ N ≤ 80,000)
두 번째 줄 부터 N+1번째 줄까지 각 빌딩의 높이가 hi 입력된다. (1 ≤ hi ≤ 1,000,000,000)

-> 오큰수랑 비슷한 문제.
N = 8 * 10^4 이므로, OK.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, num;
long long ans;
vector<int> h;
stack<int> s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    h.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        h.emplace_back(num);

        while (!s.empty() && h[s.top()] <= h[i])
        {
            s.pop();
        }

        ans += s.size();
        s.emplace(i);
    }

    cout << ans;

    return 0;
}