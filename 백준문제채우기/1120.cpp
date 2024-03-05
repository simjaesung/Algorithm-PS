#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b; cin >> a >> b;

	int ans = 0;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int val = 0;
		for (int k = 0; k < a.length(); k++) {
			if (a[k] == b[i + k]) val++;
		}
		ans = max(ans, val);
	}

	cout << a.length() - ans;
	return 0;
}