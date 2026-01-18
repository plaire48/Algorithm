/*
- 시간제한 : 0.5초 = 0.5억
- 메모리제한 : 256MB = 0.6억 int
- 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
  둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
-> 명령의 수 만개 * 명령어당 5천 미만
*/

#include <iostream>
#include <string>
using namespace std;

int n, num, sp;
string cmd;
int s[10001];
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
            s[++sp] = num;
        }
        else if (cmd == "pop")
        {
            cout << ((sp != 0) ? s[sp--] : -1) << '\n';
        }
        else if (cmd == "size")
        {
            cout << sp << '\n';
        }
        else if (cmd == "empty")
        {
            cout << ((sp == 0) ? 1 : 0) << '\n';
        }
        else if (cmd == "top")
        {
            cout << ((sp != 0) ? s[sp] : -1) << '\n';
        }
    }

    return 0;
}
