#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,M,T;
int gx, gy;
int gram=0;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int map[101][101];
int Time[101][101];
void BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin>>N>>M>>T;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>map[i][j];
            Time[i][j]=-1;
            if(map[i][j]==2){
                gx=i; gy=j;
            }
        }
    }
    BFS(1,1);

    int gramT = 2000000000; 
    if (gx != -1 && Time[gx][gy] != -1) { 
        gramT = Time[gx][gy] + (N - gx) + (M - gy);
    }

    if (Time[N][M] != -1) { 
        gramT = min(gramT, Time[N][M]);
    }

    if (gramT <= T) { 
        cout << gramT;
    } 
    else {
        cout << "Fail";
    }

    return 0;
}

void BFS(int x, int y){
    queue<pair<int, int> > mq;
    mq.push(make_pair(x, y));
    Time[x][y]=0;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>0 && nx<N+1 && ny>0 && ny<M+1 && map[nx][ny]!=1 && Time[nx][ny]==-1){
                Time[nx][ny]=Time[cx][cy]+1;
                mq.push(make_pair(nx, ny));
            }
        }
    }
}