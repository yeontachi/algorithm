#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    priority_queue<int> plusPq;
    priority_queue<int, vector<int>, greater<int> > minuspq;
    int one=0;
    int zero=0;

    for(int i=0; i<N; i++){
        int data;
        cin>>data;

        if(data>1){
            plusPq.push(data);
        }
        else if(data==1){
            one++;
        }
        else if(data==0){
            zero++;
        }
        else{
            minuspq.push(data);
        }
    }

    int sum=0;

    while(plusPq.size()>1){
        int first = plusPq.top();
        plusPq.pop();
        int second=plusPq.top();
        plusPq.pop();
        sum=sum+first*second;
    }
    if(!plusPq.empty()){
        sum=sum+plusPq.top();
        plusPq.pop();
    }

    while(minuspq.size()>1){
        int first = minuspq.top();
        minuspq.pop();
        int second=minuspq.top();
        minuspq.pop();
        sum=sum+first*second;
    }
    if(!minuspq.empty()){
        if(zero==0){
            sum=sum+minuspq.top();
            minuspq.pop();
        }
    }

    sum=sum+one;
    cout<<sum<<endl;
}