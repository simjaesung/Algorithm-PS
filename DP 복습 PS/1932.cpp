#include<iostream>
using namespace std;

int arr[505][505], d[505][505];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) cin >> arr[i][j];
		k++;
	}
	
	
	d[0][0] = arr[0][0]; k = 2;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (j == 0) d[i][j] = d[i - 1][j] + arr[i][j];
			else if (j == k - 1) d[i][j] = d[i - 1][j - 1] + arr[i][j];
			else d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + arr[i][j];
		}
		k++;
	}

	int ans = 0;
	for (auto x : d[n - 1]) ans = max(ans, x);
	cout << ans;

	return 0;
}