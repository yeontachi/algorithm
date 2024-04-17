#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H;
int box[100][100][100];
int day[100][100][100];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void BFS();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    int cnt = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                day[i][j][k] = -1;
                if (box[i][j][k] == 0) cnt++;
            }
        }
    }

    if (cnt == 0) {
        cout << 0;
        return 0;
    }

    BFS();

    int Max = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                if (day[i][j][k] > Max) {
                    Max = day[i][j][k];
                }
            }
        }
    }

    cout << Max;
    return 0;
}

void BFS() {
    queue<tuple<int, int, int>> mq;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 1) {
                    mq.push(make_tuple(i, j, k));
                    day[i][j][k] = 0;
                }
            }
        }
    }

    while (!mq.empty()) {
        int cz, cx, cy;
        tie(cz, cx, cy) = mq.front();
        mq.pop();

        for (int i = 0; i < 6; i++) {
            int nz = cz + dz[i];
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H && day[nz][nx][ny] == -1 && box[nz][nx][ny] == 0) {
                box[nz][nx][ny] = 1;
                day[nz][nx][ny] = day[cz][cx][cy] + 1;
                mq.push(make_tuple(nz, nx, ny));
            }
        }
    }
}