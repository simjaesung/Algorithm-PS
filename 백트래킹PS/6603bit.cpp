#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num[20];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) cin >> num[i];
		vector<vector<int>>s;
		for (int i = (1 << 6) - 1; i < (1 << n); i++) {
			vector<int>rotto;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					rotto.push_back(num[j]);
					cnt++;
				}
			}
			if (cnt == 6) s.push_back(rotto);
		}
		sort(s.begin(), s.end());

		for (auto x : s) {
			for (auto v : x) cout << v << ' ';
			cout << '\n';
		}
		cout << "\n";
	}
	return 0;
}