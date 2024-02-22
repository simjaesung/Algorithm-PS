#include<iostream>
using namespace std;
int arr[1000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int b, c; cin >> b >> c;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int val = arr[i] - b;
		if (val > 0) {
			if (val % c == 0) ans += val / c;
			else ans += val / c + 1;
		}
	}
	cout << ans + n;
	return 0;
}