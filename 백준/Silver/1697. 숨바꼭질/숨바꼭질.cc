#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int dx[]={-1, 1};
vector<bool> visited;
vector<int> way;
void BFS(int x);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    way.resize(100001, 0);
    visited.resize(100001, false);
    
    if(N==K) cout<<0;
    else{
        BFS(N);
        cout<<way[K];
    }
}

void BFS(int x){
    queue<int> mq;
    mq.push(x);
    visited[x]=true;
    way[x]=0;

    while(!mq.empty()){
        int cx=mq.front();
        mq.pop();

        for(int i=0; i<3; i++){
            int nx;
            if(i==2) nx=2*cx;
            else nx=cx+dx[i];

            if(nx>=0 && nx<=100000 && !visited[nx]){
                visited[nx]=true;
                mq.push(nx);
                way[nx]=way[cx]+1;
            }
        }
    }
}