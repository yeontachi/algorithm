#include <iostream>
#include <vector>
using namespace std;

int N, M, K;//N학생수, M친구관계수, K가지고 있는 돈
vector<int> A;//친구비 저장 배열
vector<int> parent;

void unionfunc(int a, int b); //합집합 만들기
int find(int a); //대표 노드 확인

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>K;

    A.resize(N+1);
    parent.resize(N+1);
    for(int i=1; i<N+1; i++){
        cin>>A[i];
    }

    for(int i=1; i<N+1; i++){
        parent[i]=i;
    }

    for(int i=1; i<M+1; i++){
        int v,w;
        cin>>v>>w;
        unionfunc(v,w);
    }

    int total=0;
    for(int i=1; i<N+1; i++){
        if(i==find(i)){
            total+=A[i];
        }
    }

    if(total<=K){
        cout<<total;
    }
    else{
        cout<<"Oh no";
    }
}

void unionfunc(int a, int b){
    a=find(a);
    b=find(b);

    if(A[a]>=A[b]){
        parent[a]=b;
    }
    else if(A[a]<A[b]){
        parent[b]=a;
    }
}

int find(int a){
    if(a==parent[a]){
        return a;
    }
    else{
        return parent[a]=find(parent[a]);
    }
}