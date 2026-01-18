/*
- 시간 제한 : 0.5초 = 1/2 * 10^8 = 5 * 10^7
- 메모리 제한 : 128MB = 0.3억 int
첫째 줄에 N(1 ≤ N ≤ 10,000), M(1 ≤ M ≤ 300,000,000)이 주어진다.
다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다.
각각의 A[x]는 30,000을 넘지 않는 자연수이다.
-> 연속 합이므로 투포인터 문제. 정렬 후 투포인터로 푼다. nlogn + n OK.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans;
long long num, sum;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    v.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.emplace_back(num);
    }

    long long rp = 0;

    for (long long lp = 0; lp < n; lp++)
    {
        while (rp < n && sum < m)
        {
            sum += v[rp++];
        }

        if (sum == m)
        {
            ans++;
        }

        sum -= v[lp];
    }

    cout << ans;

    return 0;
}
