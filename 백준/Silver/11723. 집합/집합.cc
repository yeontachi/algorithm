#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin>>M;

    vector<bool> S(21, false);

    while(M--){
        string str;
        int x;

        cin>>str;
        if(str!="all" && str!="empty") cin>>x;

        if(str=="add"){
            S[x]=true;
        }
        else if(str=="all"){
            for(int i=1; i<21; i++){
                S[i]=true;
            }
        }
        else if(str=="toggle"){
            if(S[x]) S[x]=false;
            else S[x]=true;
        }
        else if(str=="remove"){
            S[x]=false;
        }
        else if(str=="empty"){
            for(int i=1; i<21; i++){
                S[i]=false;
            }
        }
        else if(str=="check"){
            if(S[x]) cout<<"1"<<"\n";
            else cout<<"0"<<"\n";
        }
    }

    return 0;
}