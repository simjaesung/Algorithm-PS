#include<iostream>
using namespace std;

int arr[1005], d[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	d[0] = arr[0];
	int ans = d[0];
	for (int i = 1; i < n; i++) {
		d[i] = arr[i];
		for (int j = i-1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				d[i] = max(d[i], d[j] + arr[i]);
			}
		}
		ans = max(ans, d[i]);
	}

	cout << ans;
	
	return 0;
}