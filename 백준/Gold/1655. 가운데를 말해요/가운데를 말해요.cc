/*
- 시간제한 : 0.1초 = 1천만 = 10^8
- 메모리제한 : 128MB = 0.3억 int
첫째 줄에는 백준이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다.
그 다음 N줄에 걸쳐서 백준이가 외치는 정수가 차례대로 주어진다.
정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

-> 매번 insert가 이뤄짐. 중간에서 삭제없음. 가장 큰 / 작은 ~ heap.
*/

#include <iostream>
#include <queue>
using namespace std;

int n, num;
priority_queue<int> pq, min_pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        (pq.empty() || pq.top() > num) ? pq.emplace(num) : min_pq.emplace(-num);

        if (pq.size() < min_pq.size())
        {
            pq.emplace(-min_pq.top());
            min_pq.pop();
        }
        else if (pq.size() >= min_pq.size() + 2)
        {
            min_pq.emplace(-pq.top());
            pq.pop();
        }

        cout << pq.top() << '\n';
    }
    return 0;
}
