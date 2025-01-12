#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int dx[] = {-1, 1, 0, 0}; // 상하좌우 방향 이동
int dy[] = {0, 0, -1, 1};
vector<vector<int>> grid;
vector<vector<int>> dis;

void BFS(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dis[startX][startY] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크 및 방문 가능 여부 확인
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && dis[nx][ny] == -1) {
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    grid.resize(n, vector<int>(m));
    dis.resize(n, vector<int>(m, -1)); // 초기 거리를 -1로 설정

    int startX, startY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    BFS(startX, startY);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                cout << 0 << " "; // 갈 수 없는 땅
            } else {
                cout << dis[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}