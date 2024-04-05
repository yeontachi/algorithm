#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> num;

bool calculatePattern(int& a, int& b, const vector<int>& num) {
    if(num[1] == num[2]) {
        a = 1;
        b = num[2] - num[1];
    } else {
        if(num[2] - num[1] == 0) return false;
        a = (num[2] - num[3]) / (num[1] - num[2]);
        b = num[2] - num[1] * a;
    }
    for(int i = 1; i < num.size() - 1; ++i) {
        if(num[i] * a + b != num[i + 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    num.resize(N + 1);

    for(int i = 1; i <= N; ++i) {
        cin >> num[i];
    }

    if(N == 1) {
        cout << "A";
    } else if(N == 2) {
        if(num[1] == num[2]) cout << num[1];
        else cout << "A";
    } else {
        int a, b;
        if(calculatePattern(a, b, num)) {
            cout << num[N] * a + b;
        } else {
            cout << "B";
        }
    }

    return 0;
}
