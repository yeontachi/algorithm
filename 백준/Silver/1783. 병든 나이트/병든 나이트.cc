#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result;
    int N,M;
    cin>>N>>M;

    if(N==1){
        result=1;
    }
    else if(N==2){
        result=min(4,(M-1)/2+1);
    }
    else{
        if(M>=7){
            result=M-2;
        }
        else{
            result=min(4, M);
        }
    }
    cout<<result<<endl;
}