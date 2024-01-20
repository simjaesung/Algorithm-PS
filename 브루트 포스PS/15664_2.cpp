#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int  n, m, num[10], a[10];
bool c[10];
vector<vector<int>>all;

void go(int index, int start)
{
	if (index == m) {
		vector<int>v;
		for (int i = 0; i < m; i++)
			v.push_back(num[a[i]]);
		all.push_back(v);
		return;
	}
	int tmp = 0;
	for (int i = start; i < n; i++) {
		if (c[i]) continue;
		if (num[i] == tmp) continue;
		tmp = num[i];
		c[i] = 1; a[index] = i;
		go(index + 1, i);
		c[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	go(0, 0);
	//sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	for (auto& x : all) {
		for (auto& s : x) {
			cout << s << ' ';
		}
		cout << '\n';
	}
	return 0;
}