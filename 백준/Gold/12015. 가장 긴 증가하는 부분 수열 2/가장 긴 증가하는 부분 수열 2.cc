/*
- 시간제한 : 1초 = 10^8
- 메모리제한 : 512MB = 1.2억 int
가장 긴 증가하는 부분 수열 = LIS문제
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)
10^6 이므로, 무조건 NlogN문제이다. => 이분탐색
*/

#include <iostream>
#include <vector>
using namespace std;

int n, num;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.reserve(n);
    while (n--)
    {
        cin >> num;
        if (v.empty() || v.back() < num)
            v.emplace_back(num);

        v[lower_bound(v.begin(), v.end(), num) - v.begin()] = num;
    }
    cout << v.size();
    return 0;
}