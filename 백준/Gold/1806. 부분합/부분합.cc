/*
- 시간제한 : 0.5초 = 1/2 * 10^8 = 5 * 10^7
- 메모리제한 : 128MB = 0.3억 int
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다.
둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.
-> 연속된 수의 부분합 = 동일한 방향의 투포인터 문제 (N) -> 10^5.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, s, num;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    v.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.emplace_back(num);
    }

    int rp = 0;
    int sum = 0;
    int ans = 1e6;
    for (int lp = 0; lp < n; lp++)
    {
        while (rp < n && sum < s)
        {
            sum += v[rp++];
        }

        if (sum >= s)
        {
            ans = min(ans, rp - lp);
        }

        sum -= v[lp];
    }

    cout << ((ans != 1e6) ? ans : 0);

    return 0;
}