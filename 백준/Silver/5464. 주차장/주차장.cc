#include <iostream>
#include <queue>
using namespace std;

int pay[101]; 
int weight[2001]; 
int visited[101] = {0}; 
int carPosition[2001] = {0}; 

int findEmptySlot(int N, int visited[]) {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) { 
            return i;
        }
    }
    return -1; 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> pay[i];
    }

    for (int i = 1; i <= M; i++) {
        cin >> weight[i];
    }

    int totalIncome = 0;
    queue<int> waiting; 

    for (int i = 0; i < 2 * M; i++) {
        int s;
        cin >> s;
        if (s > 0) { 
            waiting.push(s);
        } else { 
            s = -s;
            totalIncome += pay[carPosition[s]] * weight[s]; 
            visited[carPosition[s]] = 0; 
        }

        while (!waiting.empty()) {
            int emptySlot = findEmptySlot(N, visited);
            if (emptySlot == -1) break; 

            int car = waiting.front();
            waiting.pop();
            visited[emptySlot] = car; 
            carPosition[car] = emptySlot; 
        }
    }

    cout << totalIncome << endl; 
}
