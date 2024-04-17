#include <iostream>
#include <queue>
using namespace std;

int R, C;
int sheep=0, wolves=0;
char grid[251][251];
bool visited[251][251];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void BFS(int x, int y);


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C;
    
    int ocnt=0;
    int vcnt=0;

    for(int i=1; i<R+1; i++){
        for(int j=1; j<C+1; j++){
            cin>>grid[i][j];
            visited[i][j]=false;
            if(grid[i][j]=='o'){
                ocnt++;
            }
            else if(grid[i][j]=='v'){
                vcnt++;
            }
        }
    }

    for(int i=1; i<R+1; i++){
        for(int j=1; j<C+1; j++){
            if(grid[i][j]=='v' && !visited[i][j]){
                BFS(i, j);
                if(sheep>wolves){
                    vcnt-=wolves;
                }
                else{
                    ocnt-=sheep;
                }
                sheep=0;
                wolves=0;
            }
        }
    }

    cout<<ocnt<<" "<<vcnt;
    return 0;
}

void BFS(int x, int y){
    queue<pair<int, int> > mq;
    mq.push(make_pair(x, y));
    visited[x][y]=true;
    wolves++;

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>0 && nx<R+1 && ny>0 && ny<C+1 && !visited[nx][ny] && grid[nx][ny]!='#'){
                if(grid[nx][ny]=='o'){
                    sheep++;
                }
                else if(grid[nx][ny]=='v'){
                    wolves++;
                }
                mq.push(make_pair(nx, ny));
                visited[nx][ny]=true;
            }
        }
    }
}