#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > DP;
vector<vector<int> > A;

int MaxSum(int n){
    int result=0;
    DP[1][1]=A[1][1];
    if(n==1) return A[1][1];
    DP[2][1]=A[1][1]+A[2][1];
    DP[2][2]=A[1][1]+A[2][2];
    result=max(DP[2][1], DP[2][2]);

    for(int i=3; i<=n; i++){
        for(int j=1; j<i+1; j++){
            if(j==1){
                DP[i][j]=A[i][j]+DP[i-1][j];
            }
            else if(j==i){
                DP[i][j]=A[i][j]+DP[i-1][j-1];
            }
            else{
                DP[i][j]=max(A[i][j]+DP[i-1][j], A[i][j]+DP[i-1][j-1]);
            }
            result = max(result, DP[i][j]);
        }
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N; //삼각형의 크기

    A.resize(N+1, vector<int>(N+1, 0));
    DP.resize(N+1, vector<int>(N+1, 0));

    for(int i=1; i<N+1; i++){
        for(int j=1; j<i+1; j++){
            int s;
            cin>>s;
            A[i][j]=s;
        }
    }

    int result=0;

    result = MaxSum(N);

    cout<<result;
    return 0;
}