#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool BFS(vector<pair<int, int> >& nodes) {
    vector<bool> visited(nodes.size(), false);
    queue<int> q;

    q.push(0); 
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (manhattan(nodes[current].first, nodes[current].second, nodes.back().first, nodes.back().second) <= 1000) {
            return true;
        }

        for (int i = 1; i < nodes.size(); i++) {
            if (!visited[i] && manhattan(nodes[current].first, nodes[current].second, nodes[i].first, nodes[i].second) <= 1000) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return false; 
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<pair<int, int> > nodes(n + 2); 

        for (int i = 0; i < n + 2; i++) {
            cin >> nodes[i].first >> nodes[i].second;
        }

        if (BFS(nodes)) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
    }

    return 0;
}