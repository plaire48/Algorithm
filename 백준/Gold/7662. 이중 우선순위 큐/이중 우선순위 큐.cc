/*
- 시간제한: 6초 = 6억
- 메모리제한 : 256MB = 0.6억 int
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다.
각 테스트 데이터의 첫째 줄에는 Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)가 주어진다.
이어지는 k 줄 각각엔 연산을 나타내는 문자(‘D’ 또는 ‘I’)와 정수 n이 주어진다.
‘I n’은 정수 n을 Q에 삽입하는 연산을 의미한다. 동일한 정수가 삽입될 수 있음을 참고하기 바란다.
‘D 1’는 Q에서 최댓값을 삭제하는 연산을 의미하며, ‘D -1’는 Q 에서 최솟값을 삭제하는 연산을 의미한다.
최댓값(최솟값)을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제됨을 유념하기 바란다.
만약 Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시해도 좋다.
Q에 저장될 모든 정수는 -2^31 이상 2^31 미만인 정수이다.

-> 삽입과 삭제가 계속 이어지며 동시에 최대 최소가 필요하다 = map
k * O(logk) = 10^5 * 5 OK.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int t, k, num;
char cmd;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> k;
        map<int, int> q;
        for (int i = 0; i < k; i++)
        {
            cin >> cmd >> num;
            if (cmd == 'I')
            {
                q[num]++;
            }
            else if (cmd == 'D')
            {
                if (q.empty())
                    continue;

                auto it = (num == 1) ? prev(q.end()) : q.begin();
                if (--it->second == 0)
                    q.erase(it);
            }
        }

        if (q.empty())
            cout << "EMPTY" << '\n';
        else
            cout << prev(q.end())->first << ' ' << q.begin()->first << '\n';
    }
    return 0;
}