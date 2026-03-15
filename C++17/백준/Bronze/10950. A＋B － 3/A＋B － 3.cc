#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;

    cin>>T;

    while(T--){
        int A, B;
        cin>>A>>B;
        int result;
        result = A+ B;
        cout<<result<<"\n";
    }
    
    return 0;
}