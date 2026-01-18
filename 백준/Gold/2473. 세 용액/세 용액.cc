/*
- 시간제한 : 1초
- 메모리제한 : 256MB = 0.6억 int
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 3 이상 5,000 이하의 정수이다.
둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다.
이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다.
N개의 용액들의 특성값은 모두 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.
-> N개수 합 찾기 = 투포인터 문제
-> 세용액이므로, nlogn + N^2 = O(N^2) = 25 * 10^6 = 2.5 * 10^7 OK.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num;
vector<long long> v;
vector<long long> ans(3);
long long min_sum;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.emplace_back(num);
    }

    sort(v.begin(), v.end());
    min_sum = 1e9 * 3;

    for (int sp = 0; sp < n; sp++)
    {
        int lp = sp + 1;
        int rp = n - 1;

        while (lp < rp)
        {
            long long sum = v[sp] + v[lp] + v[rp];

            if (abs(min_sum) > abs(sum))
            {
                min_sum = sum;
                ans[0] = v[sp];
                ans[1] = v[lp];
                ans[2] = v[rp];
            }

            if (sum == 0)
            {
                break;
            }
            else if (sum < 0)
            {
                lp++;
            }
            else
            {
                rp--;
            }
        }
        if (min_sum == 0)
        {
            break;
        }
    }

    for (const auto &e : ans)
    {
        cout << e << ' ';
    }

    return 0;
}
