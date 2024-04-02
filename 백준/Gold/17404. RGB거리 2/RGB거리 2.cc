#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e9;
int cost[1001][3]; // 각 집을 칠하는 비용
int dp[1001][3]; // dp[i][j]: i번째 집까지 고려하고, 마지막으로 j색을 사용했을 때의 최소 비용

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    int answer = INF;
    // 첫 번째 집을 각각 빨강, 초록, 파랑으로 칠하는 경우를 별도로 계산
    for (int first = 0; first < 3; ++first) {
        // 모든 색상에 대해 INF로 초기화
        for (int i = 0; i < 3; ++i) {
            fill(dp[i], dp[i] + 3, INF);
        }
        // 첫 번째 집을 현재 선택한 색으로 칠함
        dp[1][first] = cost[1][first];
        
        // 동적 프로그래밍을 이용한 최소 비용 계산
        for (int i = 2; i <= N; ++i) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }

        // 마지막 집을 첫 번째 집과 다른 색으로 칠하는 경우만 고려하여 최소 비용 계산
        for (int last = 0; last < 3; ++last) {
            if (last != first) { // 첫 번째 집과 색상이 다른 경우에 한함
                answer = min(answer, dp[N][last]);
            }
        }
    }

    cout << answer;
}