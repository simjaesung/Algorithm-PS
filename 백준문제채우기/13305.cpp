#include<iostream>
using namespace std;
typedef long long ll;

ll m[100005], d[100005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) cin >> d[i];
	for (int i = 0; i < n; i++) cin >> m[i];

	ll mm = 1000000000;	ll ans = 0;

	for (int i = 0; i < n-1; i++) {
		mm = min(mm, m[i]);
		ans += d[i] * mm;
	}
	cout << ans;
	
	return 0;
}