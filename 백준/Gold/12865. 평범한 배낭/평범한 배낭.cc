#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<int> W(N), V(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i] >> V[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 0; w <= K; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (w >= W[i - 1]) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - W[i - 1]] + V[i - 1]);
            }
        }
    }
    cout << dp[N][K] << endl;

    return 0;
}