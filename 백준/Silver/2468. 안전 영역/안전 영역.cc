#include <iostream>
#include <queue>
using namespace std;

int N;
int map[101][101];
bool visited[101][101];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void BFS(int x, int y, int r);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cin>>map[i][j];
            visited[i][j]=false;
        }
    }
    int max=0;
    int rain=0;
    
    while(true){
        int ans=0;
        for(int i=1; i<N+1; i++){
            for(int j=1; j<N+1; j++){
                visited[i][j]=false;
            }
        }

        for(int i=1; i<N+1; i++){
            for(int j=1; j<N+1; j++){
                if(map[i][j]>rain && !visited[i][j]){
                    BFS(i,j, rain);
                    ans++;
                }
            }
        }
        if(ans==0) break;

        if(max<ans) max=ans;
        rain++;
    }

    cout<<max;
}

void BFS(int x, int y, int r){
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
            if(nx>0 && nx<N+1 && ny>0 && ny<N+1 && !visited[nx][ny] && map[nx][ny]>r){
                mq.push(make_pair(nx, ny));
                visited[nx][ny]=true;
            }
        }
    }
}