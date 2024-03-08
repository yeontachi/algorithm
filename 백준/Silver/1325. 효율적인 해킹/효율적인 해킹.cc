#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int node);
static vector<vector<int> > A;
static vector<int> answer;
static vector<bool> visited;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N,M;
    cin>>N>>M;
    A.resize(N+1);
    answer.resize(N+1);

    for(int i=0; i<M; i++){
        int s,e;
        cin>>s>>e;
        A[s].push_back(e);
    }

    visited.resize(N+1);

    for(int i=0; i<N+1; i++){
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    int maxVal=0;
    for(int i=1; i<=N; i++){
        maxVal=max(maxVal, answer[i]);
    }
    for(int i=1; i<=N; i++){
        if(answer[i]==maxVal){
            cout<<i<<" ";
        }
    }
}

void BFS(int node){
    queue<int> mq;
    mq.push(node);
    visited[node]=true;
    while(!mq.empty()){
        int now_node=mq.front();
        mq.pop();
        for(int i : A[now_node]){
            if(visited[i]==false){
                visited[i]=true;
                answer[i]++;
                mq.push(i);
            }
        }
    }
}