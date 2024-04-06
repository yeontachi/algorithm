#include <iostream>
#include <queue>
using namespace std;

int M,N;
int cnt=0;
int box[1001][1001];
int day[1001][1001];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};
void BFS();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>box[i][j];
            day[i][j]=-1;
            if(box[i][j]==0){
                cnt++;
            }
        }
    }
    if(cnt==0){
        cout<<0;
        return 0;
    }

    BFS();
    
    int Max=0;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            if(box[i][j]==0){
                cout<<-1;
                return 0;
            }
            else{
                if(Max<day[i][j]){
                    Max=day[i][j];
                }
            }
        }
    }
    cout<<Max;
    return 0;
}

void BFS(){
    queue<pair<int, int> > mq;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            if(box[i][j]==1){
                mq.push(make_pair(i, j));
                day[i][j]=0;
            }
        }
    }

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>0 && nx<N+1 && ny>0 && ny<M+1 && box[nx][ny]==0 && day[nx][ny]==-1){
                box[nx][ny]=1;
                day[nx][ny]=day[cx][cy]+1;
                mq.push(make_pair(nx, ny));
            }
        }
    }
}