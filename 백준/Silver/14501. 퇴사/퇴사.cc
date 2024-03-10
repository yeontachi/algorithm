#include <iostream>
#include <algorithm> 
using namespace std;

int N;
int T[16]; // 상담을 완료하는데 걸리는 시간
int Pay[16]; // 상담을 했을 때 받을 수 있는 금액
int DP[16]; // 각 날짜별 최대 수익을 저장하는 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> Pay[i];
    }

    int Max = 0; 

    for(int i = 1; i <= N; i++) {
        if(i + T[i] <= N + 1) { 
            DP[i + T[i]] = max(DP[i + T[i]], DP[i] + Pay[i]);
            Max = max(Max, DP[i + T[i]]); 
        }
        DP[i + 1] = max(DP[i + 1], DP[i]); 
    }

    cout << Max << endl;

    return 0;
}