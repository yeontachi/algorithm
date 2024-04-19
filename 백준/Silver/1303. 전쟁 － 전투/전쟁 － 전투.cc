#include <iostream>
#include <queue>
using namespace std;

int N, M;
char grid[101][101];
bool visited[101][101];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int bfs(int x, int y, char c);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=1; i<M+1; i++){
        for(int j=1; j<N+1; j++){
            cin>>grid[i][j];
            visited[i][j]=false;
        }
    }
    int o=0;
    int e=0;
    for(int i=1; i<M+1; i++){
        for(int j=1; j<N+1; j++){
            if(grid[i][j]=='W' && !visited[i][j]){
                int result=bfs(i,j, 'W');
                o+=(result*result);
            }
            else if(grid[i][j]=='B' && !visited[i][j]){
                int result=bfs(i,j, 'B');
                e+=(result*result);
            }
        }
    }

    cout<<o<<" "<<e;
}

int bfs(int x, int y, char c){
    int cnt=1;
    queue<pair<int, int> > mq;
    mq.push(make_pair(x, y));
    visited[x][y]=true;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>0 && nx<M+1 && ny>0 && ny<N+1 && !visited[nx][ny] && grid[nx][ny]==c){
                mq.push(make_pair(nx, ny));
                cnt++;
                visited[nx][ny]=true;
            }
        }
    }
    return cnt;
}