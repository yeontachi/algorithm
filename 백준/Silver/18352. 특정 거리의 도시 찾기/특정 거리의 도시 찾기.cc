#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > A; //인접리스트로 그래프 표현
vector<int> visited;//방문 체크 배열
vector<int> answer;//정답 배열
 
void BFS(int n);//그래프 탐색

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;
    cin>>N>>M>>K>>X;

    A.resize(N+1);
    for(int i=0; i<M; i++){
        int s,e;
        cin>>s>>e;
        A[s].push_back(e); //단방향 그래프
    }
    visited.resize(N+1);

    for(int i=0; i<=N; i++){
        visited[i]= -1;
    }

    BFS(X);//시작점 부터 탐색 

    for(int i=0; i<=N; i++){
        if(visited[i]==K){
            answer.push_back(i);
        }
    }
    if(answer.empty()){
        cout<<-1<<endl;
    }
    else{
        sort(answer.begin(), answer.end());
        for(int temp : answer){
            cout<<temp<<endl;
        }
    }
}

void BFS(int n){
    queue<int> mq;
    mq.push(n);
    visited[n]++;

    while(!mq.empty()){
         int now_node=mq.front();
         mq.pop();
         for(int i : A[now_node]){
            if(visited[i]== -1){
                visited[i]=visited[now_node] + 1;
                mq.push(i);
            }
         }
    }
}