/*
- 시간제한 : 0.5초 = 5천만
- 메모리제한 : 256MB = 0.6억 int
명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
- 만 * 5천 (한 명령어당 5천 미만)
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int n, num;
string cmd;
deque<int> deq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            cin >> num;
            deq.emplace_front(num);
        }
        else if (cmd == "push_back")
        {
            cin >> num;
            deq.emplace_back(num);
        }
        else if (cmd == "pop_front")
        {
            if (!deq.empty())
            {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "pop_back")
        {
            if (!deq.empty())
            {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "size")
        {
            cout << deq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << deq.empty() << '\n';
        }
        else if (cmd == "front")
        {
            cout << ((!deq.empty()) ? deq.front() : -1) << '\n';
        }
        else if (cmd == "back")
        {
            cout << ((!deq.empty()) ? deq.back() : -1) << '\n';
        }
    }

    return 0;
}