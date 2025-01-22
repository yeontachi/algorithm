#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> P(N + 1, 0); 
    vector<int> DP(N + 1, 0); 
    
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            DP[i] = max(DP[i], DP[i - j] + P[j]);
        }
    }

    cout << DP[N] << endl;

    return 0;
}
