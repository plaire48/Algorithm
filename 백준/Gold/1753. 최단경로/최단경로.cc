/*
- 시간 제한 : 1초
- 메모리 제한 :256MB = 0.6억 int

1) 시작점에서 다른 모든 정점으로의 최단/최대 경로
2) 모든 간선의 가중치는 자연수이며 다르다.
-> 다익스트라 = E * log E
-> 3*10^5 * 5 * log 3 ~ 15log3 * 10^5 OK.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

constexpr int INF = 300000 * 10 + 1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

int v, e, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    vector<vector<pair<int, int>>> adj(v + 1);
    vector<int> dist(v + 1);

    fill(dist.begin(), dist.end(), INF);

    cin >> k;

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
    }

    dist[k] = 0;
    min_pq.emplace(0, k);

    while (!min_pq.empty())
    {
        int next_v = min_pq.top().second;
        int next_w = min_pq.top().first;
        min_pq.pop();

        if (dist[next_v] < next_w)
            continue;

        for (const auto &edge : adj[next_v])
        {
            int edge_v = edge.second;
            int edge_w = edge.first;

            if (next_w + edge_w < dist[edge_v])
            {
                dist[edge_v] = next_w + edge_w;
                min_pq.emplace(dist[edge_v], edge_v);
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << '\n';
    }

    return 0;
}
