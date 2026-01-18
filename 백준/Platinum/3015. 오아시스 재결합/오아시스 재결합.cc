/*
- 시간제한 : 1초 = 1억
- 메모리제한 : 256MB = 0.6억 int
- 오작수 / 오큰수 -> 모노스틱 스택!
- 모노스틱 스택은 N^2 -> N으로 줄여준다. 5 * 10^5 OK.
*/

#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int n, num;
long long ans;
stack<pair<int, int>> line;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int count = 1;

        while (!line.empty() && line.top().first < num)
        {
            ans += line.top().second;
            line.pop();
        }

        while (!line.empty() && line.top().first == num)
        {
            ans += line.top().second;
            count += line.top().second;
            line.pop();
        }

        if (!line.empty())
        {
            ans++;
        }
        line.emplace(num, count);
    }

    cout << ans;

    return 0;
}