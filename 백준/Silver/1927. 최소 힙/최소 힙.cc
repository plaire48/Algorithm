/*
- 시간제한 : 1초
- 메모리제한 : 128MB = 0.3억 int

첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다.
다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고,
x가 0이라면 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
x는 2^31보다 작은 자연수 또는 0이고, 음의 정수는 입력으로 주어지지 않는다.

- 맨 위의 값이 중요하고 중간에 정렬이 필요없음. -> heap.
O(nlogn) = 5 * 10^5 = OK.
*/

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> min_pq;
int n, num;
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

            cout << -1 * min_pq.top() << '\n';
            min_pq.pop();
        }
        else
        {
            min_pq.emplace(-1 * num);
        }
    }

    return 0;
}