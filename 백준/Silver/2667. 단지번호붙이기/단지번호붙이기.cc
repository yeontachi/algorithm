#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int cnt=0;
int ans[626];
char map[26][26];
bool visited[26][26];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};
void BFS(int x, int y, int index);

int main(void){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin>>N;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cin>>map[i][j];
            visited[i][j]=false;
        }
    }

    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(map[i][j]=='1' && !visited[i][j]){
                cnt+=1;
                BFS(i, j, cnt);
            }
        }
    }
    sort(ans+1, ans+cnt+1);

    cout<<cnt<<'\n';
    for(int i=1; i<cnt+1; i++){
        cout<<ans[i]<<'\n';
    }
}

void BFS(int x, int y, int index){
    queue<pair<int, int> > mq;
    mq.push(make_pair(x, y));
    visited[x][y]=true;
    ans[index]=1;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>0 && nx<N+1 && ny>0 && ny<N+1 && map[nx][ny]=='1' && !visited[nx][ny]){
                mq.push(make_pair(nx, ny));
                visited[nx][ny]=true;
                ans[index]+=1;
            }
        }
    }
}