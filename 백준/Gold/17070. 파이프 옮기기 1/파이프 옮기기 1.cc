#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int map[17][17];
int dx[3]={0,1,1};
int dy[3]={1,0,1};
int ans=0;

bool Check(int x, int y);
void DFS(int x, int y, int d);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
        }
    }

    DFS(1,2,0);
    cout<<ans;
    return 0;
}

bool Check(int x, int y){
    if(x<1 || x>N || y<1 || y>N || map[x][y]==1) return false;
    else return true;
}

void DFS(int x, int y, int d){
    if(x==N && y==N){
        ans++;
        return;
    }

    for(int i=0; i<3; i++){
        if((d==0 && i==1)||(d==1&&i==0)) continue;
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!Check(nx, ny)) continue;
        if(i==2 && (map[x+1][y]==1 || map[x][y+1]==1))continue;
        DFS(nx,ny,i);
    }
}