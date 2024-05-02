#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    vector<long long> potions(N);
    for (int i = 0; i < N; i++){
        cin >> potions[i];
    }

    sort(potions.begin(), potions.end());

    long long closest_sum = 1e18;
    long long ans[3];

    for (int i = 0; i < N - 2; i++){
        int left = i + 1, right = N - 1;
        while (left < right) {
            long long sum = potions[i] + potions[left] + potions[right];
            if (abs(closest_sum) > abs(sum)){
                closest_sum = sum;
                ans[0] = potions[i];
                ans[1] = potions[left];
                ans[2] = potions[right];
            }
            if(sum > 0) {
                right--;
            } 
            else if(sum < 0) {
                left++;
            } 
            else{
                break;
            }
        }
        if (closest_sum == 0) break;  
    }

    sort(ans, ans + 3); 
    for(int i=0; i<3; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
