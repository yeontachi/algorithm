#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 사용하기 위함

using namespace std;

int main() {
    int N;
    cin >> N; // 수의 개수 입력

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i]; // 수 입력
    }

    sort(arr.begin(), arr.end()); // 배열 정렬

    int good_count = 0; // '좋은 수'의 개수

    // 모든 수에 대하여
    for (int k = 0; k < N; ++k) {
        // 투 포인터 설정
        int i = 0, j = N - 1;
        
        // 투 포인터 알고리즘 실행
        while (i < j) {
            if (i == k) ++i; // 현재 검사하는 수는 스킵
            else if (j == k) --j; // 현재 검사하는 수는 스킵
            else {
                int sum = arr[i] + arr[j];
                if (sum == arr[k]) {
                    ++good_count;
                    break; // 중복 방지를 위해 바로 탈출
                } else if (sum < arr[k]) ++i;
                else --j;
            }
        }
    }

    cout << good_count << '\n'; // '좋은 수'의 개수 출력

    return 0;
}
