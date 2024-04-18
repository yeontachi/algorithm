#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int Max=0;
int grid[501][501];
bool visited[501][501];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    int cnt=0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            cin>>grid[i][j];
            visited[i][j]=false;
            if(grid[i][j]==1){
                cnt++;
            }
        }
    }

    if(cnt==0) {
        cout<<0<<'\n'<<Max;
        return 0;
    }

    int cntpic=0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(grid[i][j]==1 && !visited[i][j]){
                Max=max(Max, BFS(i,j));
                cntpic++;
            }
        }
    }

    cout<<cntpic<<'\n'<<Max;
}

int BFS(int x, int y){
    int cnt=1;
    queue<pair<int, int> > mq;
    mq.push(make_pair(x,y));
    visited[x][y]=true;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>0 && nx<n+1 && ny>0 && ny<m+1 && !visited[nx][ny] && grid[nx][ny]==1){
                mq.push(make_pair(nx, ny));
                cnt++;
                visited[nx][ny]=true;
            }
        }
    }

    return cnt;
}