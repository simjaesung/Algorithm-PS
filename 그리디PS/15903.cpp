#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
int arr[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<>>q;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		q.push(val);
	}

	for (int i = 0; i < m; i++) {
		ll a, b;
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		q.push(a + b);
		q.push(a + b);
	}

	ll ans = 0;
	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}

	cout << ans;
	return 0;
}