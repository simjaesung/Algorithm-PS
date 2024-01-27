#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[100001];
int c[100001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fill(c, c + 100001, 0);
		for (int i = 1; i <= n; i++) cin >> arr[i];
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 1) continue;
			vector<int>v; v.push_back(i);
			queue<int>q; q.push(i);
			int check = 0;
			while (!q.empty()) {
				int k = q.front();
				q.pop();
				if (arr[k] == i) check = 1;

				int k_check = 0;
				for (int idx = 0; idx < v.size(); idx++) {
					if (v[idx] == arr[k]) {
						k_check = 1; break;
					}
				}

				if (k_check) {
					if(check) for (int idx = 0; idx < v.size(); idx++) c[v[idx]] = 1;
				}
				else {
					v.push_back(arr[k]);
					q.push(arr[k]);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) ans++;
		}

		cout << ans << '\n';
	}
	
	
	return 0;
}