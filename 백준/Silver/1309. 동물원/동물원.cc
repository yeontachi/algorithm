#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;//사자 우리의 크기

    vector<vector<long> > DP(N+1,vector<long> (2));

    DP[0][0]=DP[0][1]=0;
    DP[1][0]=1;
    DP[1][1]=2;

    long result;

    for(int i=2; i<N+1; i++){
        DP[i][0]=(DP[i-1][0]+DP[i-1][1])%9901;
        DP[i][1]=(DP[i-1][0]*2+DP[i-1][1])%9901;
    }

    result = (DP[N][0]+DP[N][1])%9901;

    cout<<result<<"\n";

    return 0;
}