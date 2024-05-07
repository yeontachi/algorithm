#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark{
    int R, C, S, D, Z;
    bool alive;
};

int R,C,M;
vector<Shark> sharks;
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};
int ans=0;
void CatchShark(int k);
void MoveSharks();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C>>M;
    sharks.resize(M);

    for(int i=0; i<M; i++){
        cin>>sharks[i].R>>sharks[i].C>>sharks[i].S>>sharks[i].D>>sharks[i].Z;
        sharks[i].alive=true;

        if(sharks[i].D <=2) sharks[i].S %=(2*(R-1));
        else sharks[i].S %= (2*(C-1));
    }

    for(int k=1; k<=C; k++){
        CatchShark(k);
        MoveSharks();
    }

    cout<<ans;
    
    return 0;
}

void CatchShark(int k){
    for(int r=1; r<=R; r++){
        for(int i=0; i<M; i++){
            if(sharks[i].alive && sharks[i].R==r && sharks[i].C==k){
                ans+=sharks[i].Z;
                sharks[i].alive=false;
                return;
            }
        }
    }
}

void MoveSharks(){
    vector<vector<int> > grid(R+1, vector<int>(C+1, -1));

    for(int i=0; i<M; i++){
        if(!sharks[i].alive) continue;

        int s=sharks[i].S;
        int d=sharks[i].D;
        int r=sharks[i].R;
        int c=sharks[i].C;

        for(int j=0; j<s; j++){
            int nr=r+dx[d];
            int nc=c+dy[d];
            if(nr<1 || nr>R || nc<1 || nc>C){
                d=(d%2==0) ? d-1 : d+1;
                nr=r+dx[d];
                nc=c+dy[d];
            }
            r=nr;
            c=nc;
        }

        sharks[i].D=d;

        if(grid[r][c]==-1){
            grid[r][c]=i;
        }
        else{
            if(sharks[grid[r][c]].Z<sharks[i].Z){
                sharks[grid[r][c]].alive=false;
                grid[r][c]=i;
            }
            else{
                sharks[i].alive=false;
            }
        }
        sharks[i].R=r;
        sharks[i].C=c;
        sharks[i].D=d;
    }
}