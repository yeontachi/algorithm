#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int> > tree;
int ans=0;
int deletenode=0;
vector<bool> visited;
void DFS(int node);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    visited.resize(N+1);
    tree.resize(N+1);
    int root=0;

    for(int i=0; i<N; i++){
        int p;
        cin>>p;

        if(p!=-1){
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
        else root=i;
    }
    cin>>deletenode;

    if(deletenode==root){
        cout<<0<<"\n";
    }
    else{
        DFS(root);
        cout<<ans<<"\n";
    }
}

void DFS(int node){
    visited[node]=true;
    int cNode=0;

    for(int i : tree[node]){
        if(visited[i]==false && i != deletenode){
            cNode++;
            DFS(i);
        }
    }
    if(cNode==0){
        ans++;
    }
}