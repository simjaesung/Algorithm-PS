#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll arr[100005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int maxval = 0; int val = 0;
	ll ans = arr[0]; ll tmp = arr[0];

	for (int i = 0; i < n; i++) {
		if (tmp == arr[i])val++;
		else {
			if (maxval < val) {
				maxval = val;
				ans = tmp;
			}
			val = 1; tmp = arr[i];
		}
	}

	if (val > maxval) ans = arr[n - 1];

	cout << ans;

	return 0;
}