#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

void clock(deque<int> &a, int i) {
    if (i == 1) {
        a.push_front(a.back());
        a.pop_back();
    }
    else {
        a.push_back(a.front());
        a.pop_front();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> a[4];
    int n, x, y, answer = 0;
    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++) {
            a[i].push_back(str[j]-48);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        switch (x) {
        case 1:
            if (a[0].at(2) == a[1].at(6)) {
                    clock(a[0], 1*y);
            }
            else {
                if (a[1].at(2) == a[2].at(6)) {
                    clock(a[0], 1 * y);
                    clock(a[1], -1 * y);
                }
                else {
                    if (a[2].at(2) == a[3].at(6)) {
                        clock(a[0], 1 * y);
                        clock(a[1], -1 * y);
                        clock(a[2], 1 * y);
                    }
                    else {
                        clock(a[0], 1 * y);
                        clock(a[1], -1 * y);
                        clock(a[2], 1 * y);
                        clock(a[3], -1 * y);
                    }
                }
            }
            break;
        case 2:
            if (a[1].at(6) != a[0].at(2)) clock(a[0], -1 * y);
            if (a[1].at(2) == a[2].at(6)) {
                clock(a[1], 1 * y);
            }
            else {
                if (a[2].at(2) == a[3].at(6)) {
                    clock(a[1], 1 * y);
                    clock(a[2], -1 * y);
                }
                else {
                    clock(a[1], 1 * y);
                    clock(a[2], -1 * y);
                    clock(a[3], 1 * y);
                }
            }
            break;
        case 3:
            if (a[3].at(6) != a[2].at(2)) clock(a[3], -1 * y);
            if (a[1].at(2) == a[2].at(6)) {
                clock(a[2], 1 * y);
            }
            else {
                if (a[0].at(2) == a[1].at(6)) {
                    clock(a[2], 1 * y);
                    clock(a[1], -1 * y);
                }
                else {
                    clock(a[2], 1 * y);
                    clock(a[1], -1 * y);
                    clock(a[0], 1 * y);
                }
            }
            break;
        case 4:
            if (a[3].at(6) == a[2].at(2)) {
                clock(a[3], 1 * y);
            }
            else {
                if (a[1].at(2) == a[2].at(6)) {
                    clock(a[3], 1 * y);
                    clock(a[2], -1 * y);
                }
                else {
                    if (a[1].at(6) == a[0].at(2)) {
                        clock(a[3], 1 * y);
                        clock(a[2], -1 * y);
                        clock(a[1], 1 * y);
                    }
                    else {
                        clock(a[3], 1 * y);
                        clock(a[2], -1 * y);
                        clock(a[1], 1 * y);
                        clock(a[0], -1 * y);
                    }
                }
            }
            break;
        }
    }
    if (a[0].front())    answer += 1;
    if (a[1].front())    answer += 2;
    if (a[2].front())    answer += 4;
    if (a[3].front())    answer += 8;
    cout << answer;
    return 0;
}