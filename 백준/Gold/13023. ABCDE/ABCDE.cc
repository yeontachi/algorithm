#include <iostream>
#include <vector>
using namespace std;

static vector<bool> visited;
static vector<vector<int> > A;
bool arrive;
void DFS(int n, int depth);

int main(void)
{
    int N, M;
    arrive=false;
    cin>>N>>M;

    A.resize(N);
    visited=vector<bool>(N, false);

    for(int i=0; i<M; i++)
    {
        int s, e;
        cin>>s>>e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for(int i=0; i<N; i++)
    {
        DFS(i,1);
        if(arrive)
             break;
    }

    if(arrive)
        cout<<1;
    else  
        cout<<0;
}

void DFS(int n, int depth)
{
    if(depth==5 || arrive){
        arrive=true;
        return;
    }

    visited[n]=true;

    for(int i : A[n]){
        if(!visited[i]){
            DFS(i, depth+1);
        }
    }
    visited[n]=false;
}