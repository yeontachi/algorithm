#include <iostream>
using namespace std;
int d = 0, n = 0, result = 0;
int arr_d[300000] = { 0 };
int arr_n[300000] = { 0 };
int visited[300000] = { 0 };
int main() {
	cin >> d >> n;

	for (int i = 0; i < d; i++) {
		cin >> arr_d[i];
		if (i > 0 && arr_d[i - 1] < arr_d[i]) arr_d[i] = arr_d[i - 1];
	}
	for (int i = 0; i < n; i++)
		cin >> arr_n[i];



	int cnt = 0;
	for (int i = d - 1; i >= 0; i--) {
		if (arr_n[cnt] <= arr_d[i]) {
			visited[cnt] = 1 + i;
			cnt++;
		}
		if (cnt == n)
			break;
	}

	if (cnt == n)
		cout << visited[cnt - 1] << endl;
	else
		cout << 0 << endl;

	return 0;
}