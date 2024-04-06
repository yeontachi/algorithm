#include <iostream>
#include <queue>
using namespace std;

int N,M;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool visited[301][301];
int iceberg[301][301];
int icemeltin[301][301];
void BFS(int x, int y);
void melt();
int CheckZero(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>iceberg[i][j];
        }
    }
    
    int year=0;

    while(true){
        int icecnt=0;
        for(int i=1; i<N+1; i++){
            for(int j=1; j<M+1; j++){
                visited[i][j]=false;
                if(iceberg[i][j] != 0) {
                    icemeltin[i][j]=CheckZero(i,j);
                    icecnt++;
                }
                else icemeltin[i][j]=0;
            }
        }

        if(icecnt==0){
            cout<<0;
            return 0;
        }

        melt();
        year++; 
        int cnt=0;
        for(int i=1; i<N+1; i++){
            for(int j=1; j<M+1; j++){
                if(iceberg[i][j] != 0 && !visited[i][j]){
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        if(cnt>=2) break;
    }
    cout<<year;
}

void melt(){
    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            int result;
            result=iceberg[i][j]-icemeltin[i][j];

            if(result<=0) iceberg[i][j]=0;
            else iceberg[i][j]=result;
        }
    }
}

int CheckZero(int x, int y){
    int cnt=0;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>0 && nx<N+1 && ny>0 && ny<M+1 && iceberg[nx][ny]==0){
            cnt+=1;
        }
    }
    return cnt;
}

void BFS(int x, int y){ //분리됐는지 확인
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

            if(nx>0 && nx<N+1 && ny>0 && ny<M+1 && iceberg[nx][ny]!=0 && !visited[nx][ny]){
                mq.push(make_pair(nx, ny));
                visited[nx][ny]=true;
            }
        }
    }
}