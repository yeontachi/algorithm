#include <iostream>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> trueP; //진실을 아는 사람 데이터
vector<vector<int> > party;
int result;

void unionfunc(int a, int b);
int find(int a);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T; // T 진실을 아는 사람의 수
    cin>>N>>M>>T;
    trueP.resize(T);

    for(int i=0; i<T; i++){
        cin>>trueP[i];
    }
    party.resize(M);

    for(int i=0; i<M; i++){
        int party_size;
        cin>>party_size;

        for(int j=0; j<party_size; j++){
            int temp;
            cin>>temp;
            party[i].push_back(temp);
        }
    }
    parent.resize(N+1);

    for(int i=0; i<=N; i++){ //대표 노드를 자기 자신으로 초기화하기
        parent[i]=i;
    }
    //각 파티에 참여한 사람을 하나의 그룹으로 만들기 (union연산)
    for(int i=0; i<M; i++){
        int firstpeople=party[i][0];
        for(int j=1; j<party[i].size(); j++){
            unionfunc(firstpeople, party[i][j]);
        }
    }
    //각 파티에서 진실을 아는 사람과 같은 그룹에 있다면 과장할 수 없음
    for(int i=0; i<M; i++){
        bool isPossible=true;
        int cur=party[i][0];
        for(int j=0; j<T; j++){
            if(find(cur)==find(trueP[j])){
                isPossible=false;
                break;
            }
        }
        if(isPossible){
            result++;
        }
    }
    cout<<result;
}

void unionfunc(int a, int b){
    a=find(a);
    b=find(b);

    if(a!=b){
        parent[b]=a;
    }
}

int find(int a){
    if(a==parent[a]){
        return a;
    }
    else{
        return parent[a]=find(parent[a]);
    }
}