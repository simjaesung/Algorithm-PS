#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005], n, m;

int bs(int t) {
	int s = 0; int e = n - 1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (a[m] < t) s = m + 1;
		else if (a[m] > t) e = m - 1;
		else return 1;
	}
	return 0;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cin >> m;
	while (m--) {
		int t; cin >> t;
		cout << bs(t) << '\n';
	}

	return 0;
}