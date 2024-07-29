#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int grid[100][100];
bool visited[100][100];
vector<int> W;
void BFS(int n, int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N>>K;
    W.resize(5000);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            grid[i][j]=0;
            visited[i][j]=false;
        }
    }

    for(int i=0; i<K; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int j=a; j<c; j++){
            for(int k=b; k<d; k++){
                if(grid[j][k]==0){
                    grid[j][k]=1;
                }
            }
        }
    }
    int num=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j]==0 && visited[i][j]==false){
                BFS(num, i, j);
                num++;
            }
        }
    }
    W.resize(num);
    sort(W.begin(), W.end());
    cout<<num<<'\n';
    for(int i=0; i<num; i++){
        cout<<W[i]<<" ";
    }
    return 0;
}

void BFS(int n, int x, int y){
    queue<pair<int, int> > mq;
    mq.push(make_pair(x,y));
    visited[x][y]=true;
    W[n]=1;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && grid[nx][ny]==0 && visited[nx][ny]==false){
                visited[nx][ny]=true;
                mq.push(make_pair(nx, ny));
                W[n]=W[n]+1;
            }
        }
    }
}