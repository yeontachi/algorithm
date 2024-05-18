#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Room{
    int t, a, h; 
};
int N;
long long MaxHP=0; 
long long Atk;
bool Survive(long long hp, long long atk, vector<Room> &rooms);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>Atk;

    vector<Room> R(N+1);
    for(int i=1; i<N+1; i++){
        cin>>R[i].t>>R[i].a>>R[i].h;
    }

    long long start=1;
    long long end=1e18;
    long long ans=end;

    while(start<=end){
        long long mid=(start+end)/2;
        if(Survive(mid, Atk, R)){
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }

    cout<<ans;

    return 0;
}

bool Survive(long long hp, long long atk, vector<Room> &room){
    long long cHP=hp;
    for(int i=1; i<N+1; i++){
        if(room[i].t==1){
            long long cntKill=(room[i].h+atk-1)/atk;
            long long cntDie=(cHP+room[i].a-1)/room[i].a;
            if(cntKill>cntDie) return false;

            cHP-=room[i].a*(cntKill-1);
        }
        else if(room[i].t==2){
            atk+=room[i].a;
            cHP=min(hp, cHP+room[i].h);
        }
    }
    return true;
}