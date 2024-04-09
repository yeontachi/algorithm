#include <iostream>
#include <queue>
using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
int dx[]={0,0,-1,-1,1,1,-1,1};
int dy[]={-1,1,-1,1,1,-1,0,0};
void BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin>>w>>h;
        if(w==0 && h==0) break;

        int cnt=0;
        for(int i=1; i<h+1; i++){
            for(int j=1; j<w+1; j++){
                cin>>map[i][j];
                visited[i][j]=false;
            }
        }

        for(int i=1; i<h+1; i++){
            for(int j=1; j<w+1; j++){
                if(map[i][j]==1 && !visited[i][j]){
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
    mq.push(make_pair(x,y));
    visited[x][y]=true;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<8; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>0 && nx<h+1 && ny>0 && ny<w+1 && !visited[nx][ny] && map[nx][ny]==1){
                mq.push(make_pair(nx,ny));
                visited[nx][ny]=true;
            }
        }
    }
}