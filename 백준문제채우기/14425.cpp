#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	map<string, int>v;
	while (n--) {
		string s; cin >> s;
		v[s] = 1;
	}

	while (m--) {
		string f; cin >> f;
		if (v[f]) ans++;
	}
	
	cout << ans;
	return 0;
}