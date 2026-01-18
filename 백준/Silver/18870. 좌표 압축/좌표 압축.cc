/*
- 시간 제한 : 2초
- 메모리 제한 : 512MB = 1.2억 int
첫째 줄에 N이 주어진다.
둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

정렬 후 갯수 세기 : O(nlogn) + O(1) ~ 5*10^5 OK.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, order;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }

    vector<int> uni = xs;
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (const auto &x : xs)
    {
        cout << lower_bound(uni.begin(), uni.end(), x) - uni.begin() << ' ';
    }

    return 0;
}