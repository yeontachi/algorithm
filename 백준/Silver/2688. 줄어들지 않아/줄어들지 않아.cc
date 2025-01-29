#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp(65, vector<long long>(10, 0));

void preprocess() {
    // 길이 1인 경우 초기화 (한 자리 수는 모두 가능)
    for (int d = 0; d < 10; d++) {
        dp[1][d] = 1;
    }

    // DP 테이블 채우기
    for (int n = 2; n <= 64; n++) {
        for (int d = 0; d < 10; d++) {
            for (int k = d; k < 10; k++) {
                dp[n][d] += dp[n-1][k];
            }
        }
    }
}

long long countNonDecreasingNumbers(int n) {
    long long result = 0;
    for (int d = 0; d < 10; d++) {
        result += dp[n][d];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess(); // 미리 DP 테이블을 채운다.

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << countNonDecreasingNumbers(n) << '\n';
    }

    return 0;
}
