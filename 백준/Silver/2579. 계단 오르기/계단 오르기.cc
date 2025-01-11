#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> stairs(N + 1, 0); // 계단 점수 저장
    vector<int> DP(N + 1, 0);    // DP 배열

    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }

    // 초기 조건
    DP[1] = stairs[1];
    if (N >= 2) DP[2] = stairs[1] + stairs[2];
    if (N >= 3) DP[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    // 점화식 적용
    for (int i = 4; i <= N; i++) {
        DP[i] = max(DP[i - 2] + stairs[i], DP[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << DP[N] << "\n";

    return 0;
}
