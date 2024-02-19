#include<iostream>
using namespace std;

int arr[1005], d[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int ans = 1;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if(arr[i] > arr[j])	d[i] = max(d[j] + 1, d[i]);
		}
		ans = max(d[i], ans);
	}
	cout << ans;
	
	return 0;
}