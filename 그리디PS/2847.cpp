#include<iostream>
using namespace std;
int arr[105];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;
	for (int i = n-2; i >= 0; i--) {
		while (arr[i] >= arr[i + 1]) {
			arr[i]--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}