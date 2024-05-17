#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
struct C{
    int s, e, price;
    bool operator<(const C& o)const{
        return price < o.price;
    }
};
vector<int> parent;
vector<int> Rank;
void Union(int s, int e);
int find(int s);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    vector<C> c;
    c.resize(M);
    parent.resize(N+1);
    Rank=vector<int> (N+1, 0);


    for(int i=0; i<M; i++){
        cin>>c[i].s>>c[i].e>>c[i].price;
    }

    sort(c.begin(), c.end());

    for(int i=1; i<N+1; i++) parent[i]=i;

    int ans=0;

    for(auto &i : c){
        if(find(i.s)!=find(i.e)){
            Union(i.s, i.e);
            ans+=i.price;
        }
    }

    cout<<ans;
    return 0;
}

int find(int s){
    if(parent[s]!=s) parent[s]=find(parent[s]);
    return parent[s];
}

void Union(int s, int e){
    int u=find(s);
    int v=find(e);

    if(u!=v){
        if(Rank[u]>Rank[v]) parent[v]=u;
        else if(Rank[u]<Rank[v]) parent[u]=v;
        else{
            parent[v]=u;
            Rank[u]++;
        }
    }
}