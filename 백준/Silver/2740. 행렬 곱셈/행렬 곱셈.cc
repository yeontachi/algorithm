#include <iostream>
#include <vector>
using namespace std;

void multiplyVec(const vector<vector<int> >& v1, const vector<vector<int> >& v2, int n, int m, int k);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;

    cin>>N>>M;
    vector<vector<int> > v1(N, vector<int> (M, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>v1[i][j];
        }
    }

    cin>>M>>K;
    vector<vector<int> > v2(M, vector<int> (K, 0));

    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++){
            cin>>v2[i][j];
        }
    }

    multiplyVec(v1, v2, N, M, K);

    return 0;
}

void multiplyVec(const vector<vector<int> >& v1, const vector<vector<int> >& v2, int n, int m,  int k){
    vector<vector<int> > result(n, vector<int> (k, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            for(int a=0; a<m; a++){
                int r = v1[i][a] * v2[a][j];
                result[i][j]+=r;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}