#include <iostream>
#include <vector>
using namespace std;

// 안전하게 long long 사용
static vector<long long> tree;
long long getSum(int s, int e);
void changeVal(int index, long long val);
void setTree(int i);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    int treeHeight = 0;
    int Length = N;

    while(Length != 0){ 
        Length /= 2;
        treeHeight++;
    }

    // pow 대신 비트 시프트 연산(1 << n)을 사용하면 빠르고 안전합니다.
    int treeSize = 1 << (treeHeight + 1); 
    int leftNodeStartIndex = treeSize / 2 - 1;
    tree.resize(treeSize + 1);

    for(int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++){
        cin >> tree[i];
    }

    setTree(treeSize - 1);

    for(int i = 0; i < M + K; i++){
        long long a, s, e;
        cin >> a >> s >> e;

        if(a == 1){
            changeVal(leftNodeStartIndex + s, e);
        }
        else if(a == 2){
            s = s + leftNodeStartIndex;
            e = e + leftNodeStartIndex;
            cout << getSum(s, e) << "\n";
        }
    }
}

long long getSum(int s, int e){
    long long partSum = 0;

    while(s <= e){
        if(s % 2 == 1){
            partSum = partSum + tree[s];
            s++;
        }
        // 오타 수정: e % s -> e % 2
        if(e % 2 == 0){
            partSum = partSum + tree[e];
            e--;
        }
        s = s / 2;
        e = e / 2;
    }
    return partSum;
}

void changeVal(int index, long long val){
    long long diff = val - tree[index];

    while(index > 0){
        tree[index] = tree[index] + diff;
        index = index / 2;
    }
}

void setTree(int i){
    while(i != 1){
        tree[i / 2] += tree[i];
        i--;
    }
}