#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // DP 배열 선언 및 초기화
    vector<bool> DP(n + 1, false);

    // 초기값 설정
    if (n >= 1) DP[1] = false;  // 창영(CY) 승리
    if (n >= 2) DP[2] = true;   // 상근(SK) 승리
    if (n >= 3) DP[3] = false;  // 창영(CY) 승리
    if (n >= 4) DP[4] = true;   // 상근(SK) 승리

    // 점화식 계산
    for (int i = 5; i <= n; i++) {
        DP[i] = !DP[i - 1] || !DP[i - 3] || !DP[i - 4];
    }

    // 결과 출력
    cout << (DP[n] ? "SK" : "CY") << "\n";
    return 0;
}
