#include <iostream>
using namespace std;

int DP[1001];
int mod=10007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    DP[1]=1;
    DP[2]=2;

    for(int i=3; i<N+1; i++){
        DP[i]=(DP[i-1]+DP[i-2])%10007;
    }
    cout<<DP[N];
}