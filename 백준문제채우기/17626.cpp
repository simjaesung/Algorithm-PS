#include<iostream>
#include<vector>
using namespace std;
int d[50005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i * i <= 50000; i++) d[i * i] = 1;

	vector<int>v;
	for (int i = 1; i <= 50000; i++) {
		if (d[i] == 1) v.push_back(i);
		else {
			int tmp = 50000;
			for (auto x : v) tmp = min(tmp, d[x] + d[i - x]);
			d[i] = tmp;
		}
	}

	int n; cin >> n;
	cout << d[n];
	
	return 0;
}