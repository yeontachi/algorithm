#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    deque<int> dq;
    vector<int> targets(M);

    for (int i = 1; i <= N; i++) {
        dq.push_back(i); 
    }

    for (int i = 0; i < M; i++) {
        cin >> targets[i]; 
    }

    int totalMoves = 0; 

    for (int target : targets) {
        int pos = find(dq.begin(), dq.end(), target) - dq.begin(); 
        int leftMoves = pos;                 
        int rightMoves = dq.size() - pos;      

        if (leftMoves <= rightMoves) { 
            totalMoves += leftMoves;
            while (leftMoves--) { 
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else { 
            totalMoves += rightMoves;
            while (rightMoves--) { 
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        dq.pop_front(); 
    }

    cout << totalMoves << '\n'; 

    return 0;
}