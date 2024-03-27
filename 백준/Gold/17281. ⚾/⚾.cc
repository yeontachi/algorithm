#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int> > result;
int BaseAScore(vector<int> &s);//타자 순서

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    result.resize(N, vector<int>(9));

    for(int i=0; i<N; i++){
        for(int j=0; j<9; j++){
            cin>>result[i][j];
        }
    }

    vector<int> s(9);
    for(int i=0; i<9; i++){
        s[i]=i;
    }

    int MaxScore=0;

    while(next_permutation(s.begin(), s.end())){
        if(s[3]==0){
        MaxScore=max(MaxScore, BaseAScore(s));}
    }

    cout<<MaxScore<<"\n";
    return 0;
}

int BaseAScore(vector<int> &s){
    int score=0;
    int hit=0;

    for(int i=0; i<N; i++){//이닝
        int out=0;
        vector<bool> bases(4, false);

        while(out<3){
            int r=result[i][s[hit]];//현재 타자가 친 결과
            if(r==0) out++;
            else{
                bases[0]=true;
                for(int i=3; i>=0; i--){
                    if(bases[i]){
                        int nB=i+r;
                        if(nB>3) score++;
                        else{
                            bases[nB]=true;
                        }
                        bases[i]=false;
                    }
                }
            }
            hit=(hit+1)%9;
        }
    }
    return score;
}