#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<int> DP;
vector<int> price;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    DP.resize(N+1);
    price.resize(N+1);

    for(int i=1; i<N+1; i++){
        cin>>price[i];
    }

    for(int i=1; i<N+1; i++){
        DP[i]=price[i];
        for(int j=1; j<i; j++){
            DP[i]=min(DP[i], DP[i-j]+price[j]);
        }
    }

    cout<<DP[N];
}