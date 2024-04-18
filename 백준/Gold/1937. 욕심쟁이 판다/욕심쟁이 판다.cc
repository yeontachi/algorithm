#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int> > A;
vector<vector<int> > dp; 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int DFS(int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    dp[x][y] = 1; 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[x][y] < A[nx][ny]) {
            dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    A.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int Max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Max = max(Max, DFS(i, j));
        }
    }
    cout << Max << "\n";
    return 0;
}