/*
- 시간제한 : 1초
- 메모리제한 : 0.3억 int
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다.
다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데,
이 수들이 A안에 존재하는지 알아내면 된다.
모든 정수의 범위는 -2^31 보다 크거나 같고 2^31보다 작다.
-> 정렬 후, nlogn 이분탐색 OK.
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
        v.emplace_back(num);
    }

    sort(v.begin(), v.end());

    cin >> n;
    while (n--)
    {
        cin >> num;
        cout << ((binary_search(v.begin(), v.end(), num)) ? 1 : 0) << '\n';
    }
    return 0;
}