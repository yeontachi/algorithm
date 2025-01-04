#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int BFS(int I, int sx, int sy, int ex, int ey) {
    vector<vector<int>> A(I, vector<int>(I, 0));
    queue<pair<pair<int, int>, int>> mq;
    mq.push({{sx, sy}, 0});
    A[sx][sy] = 1;

    while (!mq.empty()) {
        int cx = mq.front().first.first;
        int cy = mq.front().first.second;
        int moves = mq.front().second;
        mq.pop();

        // 목표 위치에 도달하면 이동 횟수 반환
        if (cx == ex && cy == ey) {
            return moves;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < I && ny >= 0 && ny < I && A[nx][ny] == 0) {
                mq.push({{nx, ny}, moves + 1});
                A[nx][ny] = 1; // 방문 표시
            }
        }
    }
    return -1; // 도달할 수 없는 경우
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int I;
        cin >> I;

        int sx, sy;
        cin >> sx >> sy;

        int ex, ey;
        cin >> ex >> ey;

        if (sx == ex && sy == ey) {
            cout << 0 << "\n";
            continue;
        }

        cout << BFS(I, sx, sy, ex, ey) << "\n";
    }

    return 0;
}
