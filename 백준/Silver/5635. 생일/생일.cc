#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 사용하기 위함
using namespace std;

int n;

struct birth{
    string name;
    int d;
    int m;
    int y;
};

// 비교 함수를 사용하여 날짜가 더 빠른 순으로 정렬
bool cmp(const birth &v1, const birth &v2){
    if (v1.y != v2.y) {
        return v1.y < v2.y;
    } else if (v1.m != v2.m) {
        return v1.m < v2.m;
    } else {
        return v1.d < v2.d;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<birth> b(n); // 벡터의 크기를 n으로 초기화

    for (int i = 0; i < n; i++) {
        cin >> b[i].name >> b[i].d >> b[i].m >> b[i].y;
    }

    sort(b.begin(), b.end(), cmp); // 수정된 비교 함수를 사용하여 정렬

    // 가장 젊은 사람 (가장 마지막에 태어난 사람)
    cout << b[n-1].name << '\n'; 
    // 가장 나이 많은 사람 (가장 먼저 태어난 사람)
    cout << b[0].name << '\n';

    return 0;
}
