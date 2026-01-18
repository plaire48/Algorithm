#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, num, ap, bp, ab;
vector<int> A, B;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    A.reserve(a);
    B.reserve(b);

    for (int i = 0; i < a; i++)
    {
        cin >> num;
        A.emplace_back(num);
    }

    for (int i = 0; i < b; i++)
    {
        cin >> num;
        B.emplace_back(num);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    while (ap != a && bp != b)
    {
        if (A[ap] == B[bp])
        {
            ab++;
            ap++;
            bp++;
        }
        else if (A[ap] < B[bp])
        {
            ap++;
        }
        else
        {
            bp++;
        }
    }

    cout << a + b - 2 * ab;

    return 0;
}