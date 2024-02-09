#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(tuple<string, int, int, int>& a, tuple<string, int, int, int>& b) {
	string name1,name2; 
	int a1, b1, c1, a2, b2, c2;
	tie(name1, a1, b1, c1) = a;
	tie(name2, a2, b2, c2) = b;

	if (a1 != a2) return a1 > a2;
	if (b1 != b2) return b1 < b2;
	if (c1 != c2) return c1 > c2;

	return name1 < name2;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	vector<tuple<string, int, int, int>>v;

	for (int i = 0; i < n; i++) {
		string s; int a, b, c;
		cin >> s >> a >> b >> c;
		v.push_back({ s,a,b,c });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto x : v) cout << get<0>(x) << '\n';


	return 0;
}