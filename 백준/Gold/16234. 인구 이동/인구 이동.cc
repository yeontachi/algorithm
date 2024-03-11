#include <iostream>
#include <vector>
#include <queue>
#include <cmath> 
using namespace std;

int N, L, R;
int A[50][50];
bool visited[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int& totalCount, int& totalPop) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> unionCountries;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        unionCountries.push_back(make_pair(cx, cy));
        totalPop += A[cx][cy];
        totalCount++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                int popDiff = abs(A[cx][cy] - A[nx][ny]);
                if (popDiff >= L && popDiff <= R) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int newPopulation = totalPop / totalCount;
    for (auto& country : unionCountries) {
        A[country.first][country.second] = newPopulation;
    }
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int days = 0;
    while (true) {
        bool moved = false;
        fill(&visited[0][0], &visited[49][50], false); 

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    int totalCount = 0;
                    int totalPop = 0;
                    bfs(i, j, totalCount, totalPop);

                    if (totalCount > 1) moved = true; 
                }
            }
        }

        if (!moved) break; 
        days++;
    }

    cout << days << endl;
    return 0;
}