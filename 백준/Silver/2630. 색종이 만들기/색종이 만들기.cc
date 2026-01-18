/*
- 시간 제한: 1초
- 메모리 제한: 128MB

대표적인 분할정복 문제
T(N) = 4 * T(N/2) + O(N^2)

N ~ 10^3
=> a = 4, b^K = 4 이므로, N^2logN. 10^6 OK.
*/

#include <iostream>
using namespace std;

int n;
int paper[128][128];
int ans[2];

void solve(int sy, int sx, int n)
{
    int color = paper[sy][sx];
    bool is_ok = true;

    for (int y = sy; y < sy + n; y++)
    {
        for (int x = sx; x < sx + n; x++)
        {
            if (paper[y][x] != color)
            {
                is_ok = false;
                break;
            }
        }
        if (!is_ok)
            break;
    }

    if (is_ok)
    {
        ans[color]++;
        return;
    }

    int half = n / 2;
    solve(sy, sx, half);
    solve(sy, sx + half, half);
    solve(sy + half, sx, half);
    solve(sy + half, sx + half, half);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> paper[y][x];
        }
    }
    solve(0, 0, n);

    cout << ans[0] << '\n';
    cout << ans[1] << '\n';

    return 0;
}