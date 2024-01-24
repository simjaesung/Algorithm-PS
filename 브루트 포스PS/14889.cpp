#include<iostream>
#include<math.h>
#include <limits.h>
#include<vector>

using namespace std;

int ans = INT_MAX;
int s[21][21], t1[10];

void go(int idx, int select, int n, int m)
{
	if (select == m) {

		vector<int>v;
		for (int i = 1; i <= n; i++) {
			int check = 1;
			for (int j = 0; j < m; j++) {
				if (t1[j] == i) {
					//cout << i << t1[j] << '\n';
					check = 0;
					break;
				}
			}
			if (check) v.push_back(i);
		}
		int stat_t1 = 0, stat_t2 = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				stat_t1 += s[t1[i]][t1[j]];
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				stat_t2 += s[v[i]][v[j]];
			}
		}
		
		ans = min(ans, abs(stat_t2 - stat_t1));
		return;
	}

	if (idx > n) return;
	t1[select] = idx; 
	go(idx + 1, select + 1, n, m);
	t1[select] = 0; 
	go(idx + 1, select, n, m);
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> s[i][j];
	}

	go(1, 0, n, n / 2);

	cout << ans;

	return 0;
}