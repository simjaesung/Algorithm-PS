#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int num[10], a[10], c[10] = { 0 };
vector<vector<int>> all;

void go(int index, int n, int m)
{
	if (index == m){
		vector<int>v;
		for (int i = 0; i < m; i++)
			v.push_back(num[a[i]]);
		all.push_back(v);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (c[i] == 0) continue;
		c[i]--; a[index] = i;
		go(index + 1, n, m);
		c[i]++;
	}
}


int main()
{
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		c[i]++;
	}
	sort(num, num + n);
	go(0, n, m);
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	for (auto &x : all) {
		for (auto& s : x) {
			cout << s << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}   