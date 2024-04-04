#include <iostream>
#include <vector>
using namespace std;

long mod=1000000000;
long dp[101][11];
int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=1; i<10; i++){
        dp[1][i]=1;
    }
    for(int i=2; i<N+1; i++){
        dp[i][0]=dp[i-1][1];
        dp[i][9]=dp[i-1][8];

        for(int j=1; j<9; j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
        }
    }

    long sum=0;

    for(int i=0; i<10; i++){
        sum=(sum+dp[N][i])%mod;
    }

    cout<<sum;
}