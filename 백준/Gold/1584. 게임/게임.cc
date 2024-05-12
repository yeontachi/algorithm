#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 501;
const int INF = INT_MAX;
int map[MAX][MAX];
int dist[MAX][MAX];

void setArea(int x1, int y1, int x2, int y2, int val) {
    int startX = min(x1, x2);
    int startY = min(y1, y2);
    int endX = max(x1, x2);
    int endY = max(y1, y2);

    for (int x = startX; x <= endX; x++) {
        for (int y = startY; y <= endY; y++) {
            map[y][x] = val;
        }
    }
}

void initDist() {
    for (int i = 0; i < MAX; i++) {
        fill(dist[i], dist[i] + MAX, INF);
    }
}

struct Node {
    int x, y, w;
    Node(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
    bool operator<(const Node& other) const {
        return w > other.w; // Invert the comparison to make it min-heap
    }
};

void dijkstra() {
    priority_queue<Node> pq;
    pq.push(Node(0, 0, 0));
    dist[0][0] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        int cx = cur.x;
        int cy = cur.y;

        if (dist[cy][cx] < cur.w) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            if (map[ny][nx] == 2) continue;

            if (dist[ny][nx] > dist[cy][cx] + map[ny][nx]) {
                dist[ny][nx] = dist[cy][cx] + map[ny][nx];
                pq.push(Node(nx, ny, dist[ny][nx]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, x1, y1, x2, y2;
    cin >> N;

    while (N--) {
        cin >> x1 >> y1 >> x2 >> y2;
        setArea(x1, y1, x2, y2, 1);
    }

    cin >> M;

    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        setArea(x1, y1, x2, y2, 2);
    }

    initDist();
    dijkstra();

    cout << (dist[500][500] == INF ? -1 : dist[500][500]) << endl;
    return 0;
}
