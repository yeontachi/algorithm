#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int cnt=0;
int dx[]={0,0,-1,1,1,1,-1,-1};
int dy[]={-1,1,0,0,1,-1,1,-1};
int grid[101][71];
bool visited[101][71];
bool BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>grid[i][j];
            visited[i][j]=false;
        }
    }

    int temp=0;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            if(!visited[i][j] && BFS(i, j)) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

bool BFS(int x, int y){
    queue<pair<int, int> > mq;
    mq.push(make_pair(x, y));
    visited[x][y]=true;
    bool is_peak=true;
    int cur_H=grid[x][y];

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<8; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>0 && nx<=N && ny>0 && ny<=M){
                if(grid[nx][ny]>cur_H) is_peak=false;
                if(grid[nx][ny]==cur_H && !visited[nx][ny]){
                    mq.push(make_pair(nx, ny));
                    visited[nx][ny]=true;
                }
            }
        }
    }
    return is_peak;
}