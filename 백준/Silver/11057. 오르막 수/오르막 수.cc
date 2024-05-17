#include <iostream>
using namespace std;

int N;
int mod=10007;
int DP[1001][10];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0; i<10; i++){
        DP[1][i]=1;
    }

    for(int i=2; i<N+1; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                if(k<=j){
                    DP[i][j]=(DP[i][j]+DP[i-1][k])%mod;
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<10; i++){
        ans=(ans+DP[N][i])%mod;
    }

    cout<<ans;
    return 0;
}