#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    long DP[91][2];

    DP[1][1]=1;
    DP[1][0]=0;

    for(int i=2; i<=N; i++){
        DP[i][0]=DP[i-1][1]+DP[i-1][0];
        DP[i][1]=DP[i-1][0];
    }

    cout<<DP[N][0]+DP[N][1];
}
