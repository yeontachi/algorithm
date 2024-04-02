#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<int> population;
vector<vector<int>> adj;
int ans = 1e9;

// 구역의 연결성을 확인하는 함수
bool isConnected(vector<int>& area) {
    vector<bool> visited(N, false);
    vector<int> q;
    q.push_back(area[0]);
    visited[area[0]] = true;
    int count = 1;

    while (!q.empty()) {
        int current = q.back();
        q.pop_back();
        for (int next : adj[current]) {
            if (!visited[next] && find(area.begin(), area.end(), next) != area.end()) {
                visited[next] = true;
                q.push_back(next);
                count++;
            }
        }
    }

    return count == area.size();
}

// 두 선거구의 인구 차이를 계산하는 함수
void calculateDifference() {
    for (int i = 1; i < (1 << N) - 1; i++) {
        vector<int> area1, area2;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) area1.push_back(j);
            else area2.push_back(j);
        }

        if (isConnected(area1) && isConnected(area2)) {
            int population1 = 0, population2 = 0;
            for (int index : area1) population1 += population[index];
            for (int index : area2) population2 += population[index];
            ans = min(ans, abs(population1 - population2));
        }
    }
}

int main() {
    cin >> N;
    population.resize(N);
    adj.resize(N);

    for (int i = 0; i < N; i++) cin >> population[i];

    for (int i = 0; i < N; i++) {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++) {
            int v;
            cin >> v;
            adj[i].push_back(v - 1);
        }
    }

    calculateDifference();

    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
