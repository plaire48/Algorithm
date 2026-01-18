/*
- 시간제한 :1초
- 메모리 제한 : 256MB = 0.6억 int
첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다.
다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고,
x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
입력되는 자연수는 2^31보다 작다.

-> N = 10^5 / 삽입연산 = logN 이므로, NlogN = 5 * 10^5 OK.
-> 가장 큰 값만 중요해! 정렬은 굳이? 라면 굳이 map/set을 쓸필요가 없다. heap을 쓴다.
*/

#include <iostream>
#include <queue>
using namespace std;

int n, num;
priority_queue<int> pq;
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
            if (pq.empty())
            {
                cout << 0 << '\n';
                continue;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
        else
        {
            pq.emplace(num);
        }
    }

    return 0;
}
