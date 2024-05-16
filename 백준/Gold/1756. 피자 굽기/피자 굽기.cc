#include <iostream>
using namespace std;

int D=0, N=0, result=0;
int oven[300000]={0};
int pizza[300000]={0};
int ans[300000]={0};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>D>>N;

    for(int i=0; i<D; i++){
        cin>>oven[i];
        if(i>0 && oven[i-1]<oven[i]) oven[i]=oven[i-1];
    }

    for(int i=0; i<N; i++){
        cin>>pizza[i];
    }

    int cnt=0;
    for(int i=D-1; i>=0; i--){
        if(pizza[cnt]<=oven[i]){
            ans[cnt]=1+i;
            cnt++;
        }
        if(cnt==N) break;
    }

    if(cnt==N) cout<<ans[cnt-1]<<'\n';
    else cout<<0;

    return 0;
}