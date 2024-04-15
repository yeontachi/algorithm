#include <iostream>
#include <queue>
using namespace std;

int N;
int cnt1=0, cnt2=0;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char grid[101][101];
bool visited[101][101];
void BFS(int x, int y, char w);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cin>>grid[i][j];
            visited[i][j]=false;
        }
    }

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(grid[i][j]=='R' && !visited[i][j]){
                BFS(i,j, 'R');
                cnt1++;
            }
            else if(grid[i][j]=='G' && !visited[i][j]){
                BFS(i,j, 'G');
                cnt1++;
            }
            else if(grid[i][j]=='B' && !visited[i][j]){
                BFS(i,j, 'B');
                cnt1++;
            }
        }
    }
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(grid[i][j]=='G'){
                grid[i][j]='R';
            }
            visited[i][j]=false;
        }
    }
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(grid[i][j]=='R' && !visited[i][j]){
                BFS(i,j, 'R');
                cnt2++;
            }
            else if(grid[i][j]=='B' && !visited[i][j]){
                BFS(i,j, 'B');
                cnt2++;
            }
        }
    }

    cout<<cnt1<<" "<<cnt2;
    return 0;
}

void BFS(int x, int y, char w){
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
            if(nx>0 && nx<N+1 && ny>0 && ny<N+1 && !visited[nx][ny] && grid[nx][ny]==w){
                mq.push(make_pair(nx, ny));
                visited[nx][ny]=true;
            }
        }
    }
}