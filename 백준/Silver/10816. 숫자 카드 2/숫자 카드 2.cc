/*
- 시간 제한: 1초
- 메모리 제한: 256MB
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다.
둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다.
숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다.
넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다.
이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
-> 배열 인덱싱 빈도수 체크로 푼다. m + n OK.
*/

#include <iostream>
#include <vector>
using namespace std;

constexpr int OFFSET = 10000000;
int n, num, m;
vector<int> v(OFFSET * 2 + 1);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> num;
        v[num + OFFSET]++;
    }

    cin >> m;
    while (m--)
    {
        cin >> num;
        cout << v[num + OFFSET] << ' ';
    }

    return 0;
}
