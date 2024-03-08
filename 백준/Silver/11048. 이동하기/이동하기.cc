#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int> >A(n + 1, vector<int>(m + 1, 0));
	vector<vector<int> >DP(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
			DP[i][j] = A[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			DP[i][j] = A[i][j] + max(DP[i - 1][j - 1], max(DP[i - 1][j], DP[i][j - 1]));
		}
	}
	
	cout << DP[n][m] << '\n';
}