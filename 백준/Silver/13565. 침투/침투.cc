#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int M, N;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<vector<int>> grid;
vector<vector<int>> visited;

bool BFS(int x, int y) {
    queue<pair<int, int>> mq;
    mq.push({x, y});
    visited[x][y] = 1;

    while (!mq.empty()) {
        int cx = mq.front().first;
        int cy = mq.front().second;
        mq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && visited[nx][ny] == 0 && grid[nx][ny] == 0) {
                mq.push({nx, ny});
                visited[nx][ny] = 1;
                if (nx == M - 1) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    grid.resize(M, vector<int>(N));
    visited.resize(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        if (grid[0][i] == 0 && visited[0][i] == 0) {
            if (BFS(0, i)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
