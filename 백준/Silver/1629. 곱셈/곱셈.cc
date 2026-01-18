/*
- 시간제한 : 0.5초
- 메모리제한 : 128MB

1) (A * B) % C = ((A % C) * (B % C)) % C
2) T(N) = 2 * T(N/2) + N^0.
-> a = 2, b = 2, k = 0, 2 > 1 이므로, N^(log_a b) = N. N ~ 10^9 시간초과.
따라서, 이미 구한 값을 재활용 한다.
-> T(N) = 1 * T(N/2) + N^0
-> a = 1, b = 2, k = 0 1 = 1 이므로 N^0 log N ~ log N ~ 9 OK.
*/

#include <iostream>
using namespace std;

int a, b, c;
long long solve(int base, int exp, int mod)
{
    if (exp == 1)
    {
        return base % mod;
    }

    long long temp = solve(base, exp / 2, mod);

    temp = (temp * temp) % mod;
    return (exp & 1) ? (temp * (base % mod)) % mod : temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << solve(a, b, c);
    return 0;
}