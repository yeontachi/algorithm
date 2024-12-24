#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int M, N;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

vector<vector<int> > grid;
vector<vector<int> > visited;

bool BFS(int x, int y){
    queue<pair<int, int> > mq;
    mq.push(make_pair(x, y));
    visited[x][y]=1;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>0 && nx<=M && ny>0 && ny<=N && visited[nx][ny]==0 && grid[nx][ny]==0){
                mq.push(make_pair(nx, ny));
                visited[nx][ny]=1;
                if(nx==M) return true;
            }
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;

    grid.resize(M+1, vector<int> (N+1, 0));
    visited.resize(M+1, vector<int> (N+1, 0));

    for(int i=1; i<M+1; i++){
        string s;
        cin>>s;
        for(int j=1; j<N+1; j++){
            grid[i][j]=s[j-1]-'0';
        }
    }
    for(int i=1; i<N+1; i++){
        if(grid[1][i]==0 && visited[1][i]==0){
            if(BFS(1,i)){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}