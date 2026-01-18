#include <iostream>
#include <deque>
#include <string>

using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        int n;
        string p, x;
        deque<int> dq;

        cin >> p >> n >> x;

        int num;
        bool is_num = false;
        for (const auto &e : x)
        {
            if (e >= '0' && e <= '9')
            {
                is_num = true;
                num = 10 * num + (e - '0');
            }
            else if (e == '[')
            {
                num = 0;
            }
            else if (is_num && (e == ',' || e == ']'))
            {
                dq.emplace_back(num);
                num = 0;
            }
        }

        bool is_front = true;
        bool is_error = false;

        for (const auto &e : p)
        {
            if (e == 'R')
                is_front = !is_front;
            else
            {
                if (dq.empty())
                {
                    is_error = true;
                    break;
                }

                (is_front) ? dq.pop_front() : dq.pop_back();
            }
        }

        if (is_error)
        {
            cout << "error" << '\n';
            continue;
        }

        if (dq.empty())
        {
            cout << "[]" << '\n';
            continue;
        }

        cout << "[";

        cout << ((is_front) ? dq.front() : dq.back());
        (is_front) ? dq.pop_front() : dq.pop_back();

        while (!dq.empty())
        {
            cout << ',' << ((is_front) ? dq.front() : dq.back());
            (is_front) ? dq.pop_front() : dq.pop_back();
        }

        cout << "]" << '\n';
    }

    return 0;
}