#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result=0;

    for(int i=0; i<5; i++){
        int s;
        cin>>s;
        int POW=s*s;

        result+=POW;
    }

    result %= 10;

    cout<<result;

    return 0;
}