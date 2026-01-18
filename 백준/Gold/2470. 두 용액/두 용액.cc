/*
- 시간제한 : 1초
- 메모리제한 : 128MB = 0.3억 int
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하이다.
둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다.
이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다.
-> N은 작은데 숫자가 엄청 크거나 작으면 정렬문제이다. nlogn = 5 * 10^5.
-> 두 용액을 무조건 섞어야하므로 투포인터 문제로 풀 수 있다. nlogn + n = OK.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MX = 1e9 * 2;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int lp = 0;
    int rp = n - 1;
    int ans = MX;

    int min_lp, min_rp;

    while (lp < rp)
    {
        int sum = v[lp] + v[rp];
        if (abs(sum) < ans)
        {
            ans = abs(sum);
            min_lp = lp;
            min_rp = rp;
        }

        if (sum == 0)
        {
            break;
        }
        else if (sum > 0)
        {
            rp--;
        }
        else if (sum < 0)
        {
            lp++;
        }
    }
    cout << v[min_lp] << ' ' << v[min_rp];

    return 0;
}