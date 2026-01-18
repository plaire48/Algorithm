/*
- 시간제한 : 0.5초 = 0.5억
- 메모리제한 : 256MB = 0.6억 int
- 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
   둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
-> 10000 * O(1) -> 시간 제한 충족
   */

#include <iostream>
#include <string>
using namespace std;

const int MX = 10001;
int q[MX];

int n, num, head, tail;
string cmd;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            q[tail] = num;
            tail = (tail + 1) % MX;
        }
        else if (cmd == "pop")
        {
            cout << ((head != tail) ? q[head] : -1) << '\n';
            if (head != tail)
            {
                head = (head + 1) % MX;
            }
        }
        else if (cmd == "size")
        {
            cout << ((tail - head + MX) % MX) << '\n';
        }
        else if (cmd == "empty")
        {
            cout << ((head == tail) ? 1 : 0) << '\n';
        }
        else if (cmd == "front")
        {
            cout << ((head != tail) ? q[head] : -1) << '\n';
        }
        else if (cmd == "back")
        {
            cout << ((head != tail) ? q[((tail - 1 + MX) % MX)] : -1) << '\n';
        }
    }

    return 0;
}