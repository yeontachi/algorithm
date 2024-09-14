#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K; //세로 길이 N, 가로 길이 M, 음식물 쓰레기의 개수 K
int grid[101][101]; // 8층 방의 통로 격자 표현 1인 경우 음식물 쓰레기 존재, 0인경우 존재하지 않음.
bool visited[101][101];// BFS탐색 돌릴 시 방문한 칸 표시를 위한 2차원 배열
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0}; // 탐색 시 모든 방향을 탐색할 수 있도록 방향 배열 형성 앞 뒤 왼 오
int BFS(int x, int y); // 반환은 최대 크기를 반환


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>K;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            grid[i][j]=0;
            visited[i][j]=false; //배열 초기값 설정
        }
    }

    for(int i=0; i<K; i++){
        int s, e;
        cin>>s>>e;
        grid[s][e]=1;
    }

    int Max=0;

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            if(!visited[i][j] && grid[i][j]==1){//grid전체를 돌면서 방문하지 않았고, 음식물 쓰레긱 존재하면 BFS 탐색 돌리기
                Max=max(Max, BFS(i, j));//Max값을 계속 업데이트해주며 음식물 쓰레기 크기의 최댓값 구하기
            }
        }
    }

    cout<<Max;//음식물 쓰레기의 최댓값 반환
    return 0;
}

int BFS(int x, int y){
    int cnt=1;//첫 좌표는 포함이므로 1로 초기화
    queue<pair<int, int> > mq;//x,y 좌표를 한번에 담기 위해 pair선언
    mq.push(make_pair(x, y));//queue에 값 넣기
    visited[x][y]=true;//방문했으므로 true표시

    while(!mq.empty()){
        int cx=mq.front().first;
        int cy=mq.front().second;
        mq.pop();
        
        for(int i=0; i<4; i++){//모든 방향 탐색
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>0 && nx<N+1 && ny>0 && ny<M+1 && !visited[nx][ny] && grid[nx][ny]==1){
                mq.push(make_pair(nx, ny));
                visited[nx][ny]=true;
                cnt++;//최대 넓이를 구하기 위해서 조건에 맞는 탐색 시 넓이 추가
            }
        }
    }
    return cnt;//탐색한 음식물쓰레기의 넓이 반환
}