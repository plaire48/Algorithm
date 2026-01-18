/*
- 시간 제한 : 1초 = 1억
- 메모리 제한 : 512MB = 1.2억
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.
N = 10^5 ~ O(N^2)하면 터짐...
O(NlogN) > O(N) ... 이렇게 해야함..
-> O(N) 모노토닉 스택
  -> 일반적으로 N^2으로 풀기 어려운 문제는 오큰수 문제로 푼다. (스택 유형)
  모노토닉 스택: "나보다 작은 놈은 필요 없다"는 논리가 나오면 무조건 스택입니다.
*/

#include <iostream>
#include <stack>

using namespace std;
int n, num;
stack<int> S1, S2, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> num;
        S1.emplace(num);
    }

    while (!S1.empty())
    {
        num = S1.top();
        S1.pop();

        while (!S2.empty() && S2.top() <= num)
        {
            S2.pop();
        }

        ans.emplace((!S2.empty()) ? S2.top() : -1);
        S2.emplace(num);
    }

    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}