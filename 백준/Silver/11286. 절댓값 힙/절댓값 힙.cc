/*
- 시간제한 : 1초
- 메모리제한 : 256MB = 0.6억 int
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다.
다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고,
x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
입력되는 정수는 -2^31보다 크고, 2^31보다 작다.
-> 가장 큰 ~ 중간 정렬 필요없이 큰 녀석만 필요하므로 heap.
O(nlogn) = 10^5 * log5 OK.
*/

#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

int n, num;
priority_queue<pair<int, int>> min_pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> num;

        if (num == 0)
        {
            if (min_pq.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            cout << -1 * min_pq.top().second << '\n';
            min_pq.pop();
        }
        else
        {
            min_pq.emplace(-1 * abs(num), -1 * num);
        }
    }

    return 0;
}
