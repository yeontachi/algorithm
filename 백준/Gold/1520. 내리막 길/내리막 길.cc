#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int> > map;
vector<vector<int> > dp;  // 메모이제이션을 위한 배열
int dx[] = {0, 1, 0, -1};  // 상, 하, 좌, 우 방향
int dy[] = {-1, 0, 1, 0};

int dfs(int y, int x) {
    if (y == M - 1 && x == N - 1) {
        return 1;
    }
    if (dp[y][x] != -1) {
        return dp[y][x];
    }
    
    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < M && nx >= 0 && nx < N && map[ny][nx] < map[y][x]) {
            dp[y][x] += dfs(ny, nx);
        }
    }
    return dp[y][x];
}

int main() {
    cin >> M >> N;
    map.resize(M, vector<int>(N));
    dp.resize(M, vector<int>(N, -1));
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    cout << dfs(0, 0) << endl;
    return 0;
}