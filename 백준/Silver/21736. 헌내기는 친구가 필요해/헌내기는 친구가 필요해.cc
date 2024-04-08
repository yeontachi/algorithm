#include <iostream>
#include <queue>
using namespace std;

int N, M;
int cnt=0;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char cam[601][601];
bool visited[601][601];
void BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    int sx, sy;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>cam[i][j];
            visited[i][j]=false;
            if(cam[i][j]=='I'){
                sx=i;
                sy=j;
            }
        }
    }

    BFS(sx,sy);

    if(cnt==0) cout<<"TT";
    else cout<<cnt;
    return 0;
}

void BFS(int x, int y){
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

            if(nx>0 && nx<N+1 && ny>0 && ny<M+1 && !visited[nx][ny] && cam[nx][ny]!='X'){
                if(cam[nx][ny]=='P') cnt++;
                visited[nx][ny]=true;
                mq.push(make_pair(nx, ny));
            }
        }
    }
}