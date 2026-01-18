/*
- 시간 제한 : 2초
- 메모리 제한 : 128MB = 0.3억 int
N이 주어진다. 이 값은 1,000보다 작거나 같은 자연수이다.
둘째부터 N개의 줄에 책의 제목이 입력으로 들어온다.

- 빈도수 = 키, 값이 필요하므로 map
- O(nlogn + n) = O(NlogN) = 3* 10^3 OK.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, ans;
string s;
string ans_title;

map<string, int> books;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> s;
        books[s]++;
    }

    for (const auto &book : books)
    {
        if (book.second > ans)
        {
            ans = book.second;
            ans_title = book.first;
        }
    }

    cout << ans_title;

    return 0;
}