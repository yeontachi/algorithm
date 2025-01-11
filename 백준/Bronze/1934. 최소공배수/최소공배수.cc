#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    return (abs(a*b)/gcd(a, b));
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    while(T--){
        int a, b;
        cin>>a>>b;

        int result = lcm(a, b);

        cout<<result<<"\n";
    }

    return 0;
}