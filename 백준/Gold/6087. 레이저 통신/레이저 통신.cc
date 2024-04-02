#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char v[101][101];
vector<pair<int,int>>vv;
int mirror[101][101];
queue<pair<pair<int,int>,pair<int,int>>>q;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int W,H;
    cin>>W>>H;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin>>v[i][j];
            if(v[i][j]=='C') vv.push_back({i,j});
            mirror[i][j]=-1;
        }
    }
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    q.push({{vv[0].first, vv[0].second},{-1,-1}});
    while(!q.empty()) {
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        for(int i=0; i<4; i++) {
            int x=qx+dx[i];
            int y=qy+dy[i];
            if(x>=0 && x<H && y>=0 && y<W) {
                if(v[x][y]=='.') {
                    if(mirror[x][y]==-1 || mirror[x][y]>cnt) {
                        if(dir!=i) mirror[x][y]=cnt+1;
                        else mirror[x][y]=cnt;
                        q.push({{x,y},{i,mirror[x][y]}});
                    }
                }
                else if(x==vv[1].first && y==vv[1].second) {
                    if(mirror[x][y]==-1) {
                        if(dir!=i) mirror[x][y]=cnt+1;
                        else mirror[x][y]=cnt;
                    }
                    else {
                        if(dir!=i) mirror[x][y]=min(mirror[x][y], cnt+1);
                        else mirror[x][y]=min(mirror[x][y], cnt);
                    }
                }
            }
        }
        q.pop();
    }
    cout<<mirror[vv[1].first][vv[1].second];
}