#include <iostream>

int		dp[1001];

void	stone(int n)
{
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	for (int i = 5; i <= n; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
			dp[i] = 1;
		else dp[i] = 0;
	}
}

int		main()
{
	int n;
	std::cin >> n;
	stone(n);
	if (dp[n] == 1) std::cout << "SK";
	else std::cout << "CY";

	return (0);
}