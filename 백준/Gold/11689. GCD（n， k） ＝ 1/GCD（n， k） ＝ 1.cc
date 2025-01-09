#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin>>n;
    long result = n;

    for(long p = 2; p<=sqrt(n); p++){
        if(n%p==0){
            result = result-result/p;

            while(n%p==0) n/=p;
        }
    }

    if(n>1){
        result = result - result/n;
    }

    cout<<result<<"\n";
}