#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int ArithmeticMean(const vector<int> &A);//소수점 이하 첫째 자리에서 반올림한 값을 출력
int Median(const vector<int> &A);
int Mode(const vector<int> &A);
int Range(const vector<int> &A);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N; //수의 개수 N

    vector<int> A(N,0);

    for(int i=0; i<N; i++){
        int s;
        cin>>s;

        A[i]=s;
    }

    sort(A.begin(), A.end()); //오름차순 정렬  

    cout<<ArithmeticMean(A)<<endl;
    cout<<Median(A)<<endl;
    cout<<Mode(A)<<endl;
    cout<<Range(A)<<endl;

    return 0;
}

int ArithmeticMean(const vector<int> &A){
    double result=0;
    for(int i=0; i<A.size(); i++){
        result+=A[i];
    }

    return round(result/A.size());//반올림 함수 round
}
int Median(const vector<int> &A){
    int INDEX;
    INDEX=A.size()/2;

    return A[INDEX];
}

int Mode(const vector<int> &A) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    vector<int> modes;

    for (int num : A) {//빈도 계산
        freq[num]++;
        maxFreq = max(maxFreq, freq[num]);
    }

    // 최대 빈도에 해당하는 값들을 모음
    for (const auto &pair : freq) {
        if (pair.second == maxFreq) {
            modes.push_back(pair.first);
        }
    }

    // 두 번째로 작은 값을 반환
    sort(modes.begin(), modes.end());
    return modes.size() > 1 ? modes[1] : modes[0];
}

int Range(const vector<int> &A){
    return A.back() - A.front();
}