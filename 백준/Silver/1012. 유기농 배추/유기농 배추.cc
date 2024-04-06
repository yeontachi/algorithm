#include <iostream>
#include <queue>
using namespace std;

int T, M, N, K;
int grid[50][50];
bool visited[50][50];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;

    while(T--){
        int cnt=0;
        cin>>M>>N>>K;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                grid[i][j]=0;
                visited[i][j]=false;
            }
        }
        for(int i=0; i<K; i++){
            int s, e;
            cin>>s>>e;
            grid[e][s]=1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
}

void BFS(int x, int y){
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

            if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && grid[nx][ny]==1){
                visited[nx][ny]=true;
                mq.push(make_pair(nx, ny));
            }
        }
    }
}