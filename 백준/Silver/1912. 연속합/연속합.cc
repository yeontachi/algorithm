#include <iostream>
#include <algorithm>
using namespace std;

vector<int> DP;
vector<int> A;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    A.resize(n+1);
    DP.resize(n+1);
    for(int i=1; i<n+1; i++){
        cin>>A[i];
    }

    int Max=A[1];
    DP[1]=A[1];
    for(int i=2; i<n+1; i++){
        DP[i]=max(DP[i-1]+A[i], A[i]);
        Max=max(Max, DP[i]);
    }

    cout<<Max;
}