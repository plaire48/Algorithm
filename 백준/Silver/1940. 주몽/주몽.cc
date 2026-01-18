/*
- 시간제한 : 1초 = 10^8
- 메모리제한 : 128MB = 0.3억 int
첫째 줄에는 재료의 개수 N(1 ≤ N ≤ 15,000)이 주어진다.
그리고 두 번째 줄에는 갑옷을 만드는데 필요한 수 M(1 ≤ M ≤ 10,000,000) 주어진다.
그리고 마지막으로 셋째 줄에는 N개의 재료들이 가진 고유한 번호들이 공백을 사이에 두고 주어진다.
고유한 번호는 100,000보다 작거나 같은 자연수이다.
-> N이 15000 이므로, NlogN OK.
-> 임의의 두 수의 합을 묻는 문제이다. = 다른 방향 투포인터 문제.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m, num, ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    v.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.emplace_back(num);
    }

    sort(v.begin(), v.end());

    int lp = 0;
    int rp = n - 1;

    while (lp < rp)
    {
        if (v[lp] + v[rp] == m)
        {
            ans++;
            lp++;
            rp--;
        }
        else if (v[lp] + v[rp] < m)
        {
            lp++;
        }
        else
        {
            rp--;
        }
    }

    cout << ans;

    return 0;
}