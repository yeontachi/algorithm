#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > tree;
vector<int> ans;
vector<bool> visited;
void DFS(int rnode);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    visited.resize(N+1);
    ans.resize(N+1);
    tree.resize(N+1);

    for(int i=1; i<N+1; i++){
        int s,e;
        cin>>s>>e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    DFS(1);

    for(int i=2; i<N+1; i++){
        cout<<ans[i]<<"\n";
    }
}

void DFS(int rnode){
    visited[rnode]=true;

    for(int i : tree[rnode]){
        if(!visited[i]){
            ans[i]=rnode;
            DFS(i);
        }
    }
}