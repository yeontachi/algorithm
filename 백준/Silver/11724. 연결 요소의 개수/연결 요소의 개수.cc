#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int> > A; // 그래프 데이터 저장 인접 리스트
static vector<bool> visited; //방문 기록 저장 배열
void DFS(int v);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    A.resize(N+1);
    visited=vector<bool>(N+1, false); //방문 기록 저장 배열 초기값 false로 초기화

    for(int i=0; i<M; i++)
    {
        int s, e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    int count =0;

    for(int i=1; i<N+1; i++){ //방문하지 않은 노드가 없을 때까지 반복
        if(!visited[i]){
            count++;
            DFS(i);
        }
    }
    cout<<count<<endl;
}

void DFS(int v){
    if(visited[v]){
        return;
    }

    visited[v]=true;

    for(int i : A[v]){
        if(visited[i]==false) //연결 노드 중 방문하지 않은 노드만 탐색함
            DFS(i);
    }
}