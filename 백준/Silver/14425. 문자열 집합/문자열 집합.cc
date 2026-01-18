/*
- 시간제한 : 2초 = 2억
- 메모리제한 : 1536MB ~ 3.6억 int
첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다.

- N = 10^4, M = 10^5
존재여부를 파악하는 문제 = set
- N = 작으므로, 그냥 unordered_set이 아닌 set을 써도 된다.
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

int n, m, ans;
set<string> ss;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (n--)
    {
        cin >> s;
        ss.emplace(s);
    }

    while (m--)
    {
        cin >> s;
        if (ss.count(s))
            ans++;
    }

    cout << ans;
    return 0;
}