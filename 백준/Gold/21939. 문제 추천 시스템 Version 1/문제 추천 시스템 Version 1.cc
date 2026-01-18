/*
- 시간제한 : 1초
- 메모리제한 : 512MB = 1.2억 int
첫 번째 줄에 추천 문제 리스트에 있는 문제의 개수 N가 주어진다.
두 번째 줄부터 N + 1 줄까지 문제 번호 P와 난이도 L가 공백으로 구분되어 주어진다.
 N + 2줄은 입력될 명령문의 개수 M이 주어진다.
그 다음줄부터 M개의 위에서 설명한 명령문이 입력된다.
1 <= N, P <= 100,000
1 <= M <= 10,000
1 <= L <= 100, L은 자연수
x = +-1

-> 삽입 삭제가 자주 일어나고 + 매 삽입 삭제 마다 최대 최소가 필요하다 + key만 필요 = set
-> N * O(logN) = 10^5 * 5 OK.
*/

#include <iostream>
#include <set>
#include <string>
#include <utility>
using namespace std;

constexpr int MX = 100000;
int n, p, l, m, x;
int ls[MX];
string s;
set<pair<int, int>> problems;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> p >> l;
        ls[p] = l;
        problems.emplace(l, p);
    }

    cin >> m;
    while (m--)
    {
        cin >> s;
        if (s == "recommend")
        {
            cin >> x;
            auto it = (x == 1) ? prev(problems.end()) : problems.begin();
            cout << it->second << '\n';
        }
        else if (s == "add")
        {
            cin >> p >> l;
            problems.emplace(l, p);
        }
        else if (s == "solved")
        {
            cin >> p;
            problems.erase({ls[p], p});
        }
    }
    return 0;
}