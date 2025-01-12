#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<int> remainders; // 고유한 나머지를 저장할 set

    for (int i = 0; i < 10; i++) {
        int s;
        cin >> s;
        remainders.insert(s % 42); // 나머지를 set에 추가
    }

    cout << remainders.size() << "\n"; // 고유한 나머지 개수 출력

    return 0;
}
