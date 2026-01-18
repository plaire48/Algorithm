/*
- 시간제한 : 2초
- 메모리제한 : 0.3억 int
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K,
그리고 필요한 랜선의 개수 N이 입력된다.
K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다.
그리고 항상 K ≦ N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다.
랜선의 길이는 2^31-1보다 작거나 같은 자연수이다.

-> parametric search문제 : klog(2^31) = 10^4 * 31 OK.
*/

#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int> &v, long long cut, int max_num);

int n, k, num, ans, max_num;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    v.reserve(k);

    while (k--)
    {
        cin >> num;
        max_num = (num > max_num) ? num : max_num;
        v.emplace_back(num);
    }

    cout << binary_search(v, n, max_num);
    return 0;
}

int binary_search(const vector<int> &v, long long cut, int max_num)
{
    long long sp = 1;
    long long ep = max_num;
    long long max_mid = -1;

    while (sp <= ep)
    {
        long long mid = sp + (ep - sp) / 2;
        long long ans = 0;

        for (const auto &e : v)
        {
            ans += int(e / mid);
        }

        if (ans < cut)
        {
            ep = mid - 1;
        }
        else
        {
            max_mid = (max_mid < mid) ? mid : max_mid;
            sp = mid + 1;
        }
    }
    return max_mid;
}