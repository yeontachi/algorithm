#include <iostream>
#include <queue>
using namespace std;
int N, L, R, A[50][50], d[] = {0, 1, 0, -1, 0}, ans;
bool move() {
    bool visited[50][50] = {}, flag = false;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visited[i][j]) {
                visited[i][j] = true;
                int sum = A[i][j], cnt = 1;
                queue<pair<int, int>> u;
                q.push({i, j});
                u.push({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = x + d[k], ny = y + d[k + 1];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && abs(A[x][y] - A[nx][ny]) >= L && abs(A[x][y] - A[nx][ny]) <= R) {
                            q.push({nx, ny});
                            u.push({nx, ny});
                            visited[nx][ny] = true;
                            sum += A[nx][ny];
                            ++cnt;
                        }
                    }
                }
                if (cnt > 1) {
                    flag = true;
                    int newVal = sum / cnt;
                    while (!u.empty()) {
                        auto [x, y] = u.front(); u.pop();
                        A[x][y] = newVal;
                    }
                }
            }
    return flag;
}
int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> A[i][j];
    while (move()) ++ans;
    cout << ans;
}
