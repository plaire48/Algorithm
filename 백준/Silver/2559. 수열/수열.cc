/*
- 시간제한: 1초 = 1억
- 메모리제한: 128MB = 0.3억 int
첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로 주어진다.
첫 번째 정수 N은 온도를 측정한 전체 날짜의 수이다.
N은 2 이상 100,000 이하이다.
두 번째 정수 K는 합을 구하기 위한 연속적인 날짜의 수이다. K는 1과 N 사이의 정수이다.
둘째 줄에는 매일 측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -100 이상 100 이하이다.

-> N = 10^5, O(N) = 10^5 시간 OK.
*/

#include <iostream>
using namespace std;

constexpr int MX = 100000;

int n, k;
int ans, tmp;
int nums[MX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < k; i++)
    {
        tmp += nums[i];
    }
    ans = tmp;

    for (int i = k; i < n; i++)
    {
        tmp += nums[i] - nums[i - k];
        ans = (ans < tmp) ? tmp : ans;
    }

    cout << ans;

    return 0;
}