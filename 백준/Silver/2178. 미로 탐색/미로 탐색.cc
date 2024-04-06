#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[101][101];
int dis[101][101];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>map[i][j];
            dis[i][j] = 0;
        }
    }

    BFS(1,1);

    cout<<dis[N][M];
}

void BFS(int x, int y){
    queue<pair<int, int> > mq;
    mq.push(make_pair(x,y));
    dis[x][y]=1;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>0 && nx<N+1 && ny>0 && ny<M+1 && map[nx][ny]=='1' && dis[nx][ny]==0){
                mq.push(make_pair(nx, ny));
                dis[nx][ny]=dis[cx][cy]+1;
            }
        }
    }
}