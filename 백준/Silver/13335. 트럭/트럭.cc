#include <iostream>
#include <queue>
using namespace std;

int n, w, L;
queue<int> bridge;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w >> L;
    vector<int> truckW(n);
    for(int i=0; i<n; i++){
        cin >> truckW[i];
    }

    int time = 0, weightOnBridge = 0, idx = 0;

    for(int i=0; i<w; i++) bridge.push(0);

    while(idx < n){
        weightOnBridge -= bridge.front();
        bridge.pop();
        
        if(weightOnBridge + truckW[idx] <= L){
            bridge.push(truckW[idx]);
            weightOnBridge += truckW[idx];
            idx++;
        } else {
            bridge.push(0);
        }
        time++;
    }

    cout << time + w; 
}