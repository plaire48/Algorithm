/*
- 시간 제한 : 1초
- 메모리 제한 : 256MB
첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.

하노이탑 T(N) = 2T(N-1) + 1.
sum = 2^N-1 ~ 2^20 - 1 ~ 10^6 OK.
*/

#include <iostream>
using namespace std;

int n;

void solve(int n, int start, int via, int end)
{
    if (n == 1)
    {
        cout << start << ' ' << end << '\n';
        return;
    }

    solve(n - 1, start, end, via);

    cout << start << ' ' << end << '\n';

    solve(n - 1, via, start, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << (1 << n) - 1 << '\n';
    solve(n, 1, 2, 3);

    return 0;
}
