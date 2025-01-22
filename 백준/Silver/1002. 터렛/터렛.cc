#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//터렛 사이 거리

        if (distance == 0 && r1 == r2) {//원 일치
            cout << -1 << endl;
        } else if (distance > r1 + r2 || distance < abs(r1 - r2)) {//안접함
            cout << 0 << endl;
        } else if (distance == r1 + r2 || distance == abs(r1 - r2)) {//한점
            cout << 1 << endl;
        } else {//두 점에서 접함
            cout << 2 << endl;
        }
    }
    return 0;
}