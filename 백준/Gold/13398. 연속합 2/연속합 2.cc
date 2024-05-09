#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][2];
vector<int> v;
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	int res = v[0];

	for (int i = 0; i < N; i++)
	{
		dp[i][0] =dp[i][1] =v[i];
		if (i != 0) {
			dp[i][0] = max(dp[i][0],dp[i -1][0]+ v[i]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]+v[i]);
		}
		res = max(res, max(dp[i][0], dp[i][1]));
	}
	cout << res;
}