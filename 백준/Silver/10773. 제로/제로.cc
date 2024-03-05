#include <iostream>
#include <stack>
using namespace std;

int main(void){
    int K;
    cin>>K;
    int result=0;
    stack<int> ms;
    for(int i=0; i<K; i++){
        int s;
        cin>>s;
        if(s==0){
            if(!ms.empty()){
                ms.pop();
            }
        }
        else{
            ms.push(s);
        }
    }
    while(!ms.empty()){
        result+=ms.top();
        ms.pop();
    }
    cout<<result<<endl;
    return 0;
}