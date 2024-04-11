#include <iostream>
using namespace std;

int N, M;
int VIP[41]; 
int DP[41]; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        cin >> VIP[i];
    }
    VIP[M+1] = N+1; 

    DP[0] = 1; 
    DP[1] = 1; 
    DP[2] = 2; 

    for(int i = 3; i <= N; i++) { 
        DP[i] = DP[i-1] + DP[i-2];
    }

    int temp = 0;
    int ans = 1;
    for(int i = 1; i <= M+1; i++) {
        int gap = VIP[i] - temp - 1; 
        ans *= DP[gap]; 
        temp = VIP[i];
    }

    cout << ans << '\n';
    return 0;
}