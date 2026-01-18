/*
- 시간제한 : 1초
- 메모리 제한 : 128MB = 0.3억 int
첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다.
둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.
-> 매개변수탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, num;
vector<int> v;

int parametric_search(const vector<int> &v, int n, int c)
{
    int sp = 1;
    int ep = v[n - 1] - v[0];

    while (sp <= ep)
    {
        int mid = sp + (ep - sp) / 2;

        int front = v[0];
        int use = 1;
        for (int i = 1; i < n; i++)
        {
            if ((v[i] - front >= mid))
            {
                use++;
                front = v[i];
            }

            if (use >= c)
                break;
        }

        if (use >= c)
        {
            sp = mid + 1;
        }
        else
        {
            ep = mid - 1;
        }
    }

    return ep;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.emplace_back(num);
    }

    sort(v.begin(), v.end());

    cout << parametric_search(v, n, c);
    return 0;
}