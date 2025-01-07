#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPalindrome(int target);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N;
    cin >> N;

    // 동적 배열로 소수 판별 배열 생성
    vector<long> A(10000001, 0);

    // 에라토스테네스의 체 초기화
    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++) {
        if (A[i] == 0) continue;
        for (int j = i + i; j < 10000001; j += i) { // i의 배수만 제거
            A[j] = 0;
        }
    }

    // 입력값 N 이상의 소수 중 가장 작은 팰린드롬 수 찾기
    int i = N;

    while (true) {
        if (A[i] != 0) { // 소수일 경우
            int result = A[i];
            if (isPalindrome(result)) { // 팰린드롬 여부 확인
                cout << result << "\n";
                break;
            }
        }
        i++;
    }

    return 0;
}

// 팰린드롬 확인 함수
bool isPalindrome(int target) {
    string temp_str = to_string(target);
    int s = 0;
    int e = temp_str.size() - 1;

    while (s < e) {
        if (temp_str[s] != temp_str[e]) return false;
        s++;
        e--;
    }
    return true;
}
