/*
- 시간제한 : 2초
- 메모리제한 : 256MB = 0.6 int

첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다.
이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다.
이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

1) 투포인터 : O(logN + logM + N+M) = O(N) = 5*10^5 OK.
2) set : O(logN + logM + MlogN) = 2.5*10^6 OK.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

constexpr int MX = 500000;
string a[MX];
string b[MX];
string ans[MX];

int n, m, ap, bp, cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    while (ap != n && bp != m)
    {
        if (a[ap] == b[bp])
        {
            ans[cnt++] = a[ap];
            ap++;
            bp++;
        }
        else if (a[ap] > b[bp])
        {
            bp++;
        }
        else
        {
            ap++;
        }
    }

    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}