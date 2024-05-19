#include <iostream>
#include <queue>
using namespace std;

int N, M;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int grid[102][102];
bool visited[102][102];
int ans=0;
int Time=0;
bool meltin();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>grid[i][j];
        }
    }

    while(true){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                visited[i][j]=false;
            }
        }
        if(meltin()) break;
    }

    cout<<Time-1<<'\n'<<ans;

    return 0;
}

bool meltin(){
    queue<pair<int, int> > mq;
    mq.push(make_pair(0,0));
    visited[0][0]=true;
    Time++;
    int cheeze=0;
    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny]){
                if(grid[nx][ny]==0) mq.push(make_pair(nx, ny));
                else{
                    grid[nx][ny]=0;
                    cheeze++;
                }
                visited[nx][ny]=true;
            }
        }
    }
    if(cheeze==0) return 1;
    else{
        ans=cheeze;
        return 0;
    }
}