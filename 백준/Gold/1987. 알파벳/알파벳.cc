#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char grid[20][20];
bool visited[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int max_path = 0;

void dfs(int x, int y, int depth) {
    max_path = max(max_path, depth);  // 최대 길이 갱신
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {  // 경계 체크
            int index = grid[nx][ny] - 'A';
            if (!visited[index]) {  // 아직 방문하지 않은 알파벳이면
                visited[index] = true;
                dfs(nx, ny, depth + 1);
                visited[index] = false;  // 방문 기록 해제
            }
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    visited[grid[0][0] - 'A'] = true;  // 시작점 방문 처리
    dfs(0, 0, 1);  // 시작점, 깊이 1부터 시작
    cout << max_path << endl;  // 최대 길이 출력
    return 0;
}
