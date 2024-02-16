#include<iostream>
using namespace std;
int arr[305],d[305][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	d[1][0] = arr[1];
	d[2][0] = arr[2]; d[2][1] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		d[i][0] = max(d[i - 2][0], d[i - 2][1]) + arr[i];
		d[i][1] = d[i - 1][0] + arr[i];
	}

	cout << max(d[n][0], d[n][1]);

	return 0;
}