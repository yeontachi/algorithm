#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 무한대 값 설정

// 다익스트라 알고리즘을 구현하는 함수
vector<int> dijkstra(int N, vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(N + 1, INF); // 최소 거리 배열, INF로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start}); // (비용, 도시)

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (cost > dist[current]) continue; // 이미 처리된 노드면 무시

        for (auto &next : graph[current]) {
            int nextCity = next.first;
            int nextCost = cost + next.second;

            if (nextCost < dist[nextCity]) {
                dist[nextCity] = nextCost;
                pq.push({nextCost, nextCity});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); // u에서 v로 가는 비용 w
    }

    int start, end;
    cin >> start >> end;

    vector<int> dist = dijkstra(N, graph, start);

    cout << dist[end] << '\n'; // 최소 비용 출력

    return 0;
}
