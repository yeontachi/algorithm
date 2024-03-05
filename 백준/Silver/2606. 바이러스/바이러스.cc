#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void BFS(int node);
vector<vector<int> > A;
vector<bool> visited;
int virus=0;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int com, cnt;//com>컴퓨터 개수 cnt>>연결되어있는 컴퓨터 쌍의수
    cin>>com>>cnt;

    A.resize(com+1);
    visited=vector<bool> (com+1, false);
    for(int i=0; i<cnt; i++){
        int s, e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    BFS(1);

    cout<<virus<<endl;
}

void BFS(int node)
{
    queue<int> mq;
    mq.push(node);
    visited[node]=true;

    while(!mq.empty()){
        int now_node=mq.front();
        mq.pop();
        for(int i : A[now_node]){
            if(!visited[i]){
                visited[i]=true;
                mq.push(i);
                virus++;
            }
        }
    }
}