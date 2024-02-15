#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits.h>
#include<tuple>
using namespace std;

int arr[55][55];
int n, m, ans = INT_MAX;


vector<pair<int, int>>virus;

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) virus.push_back({ i,j });
		}
	}
	vector<int>v;
	for (int i = 0; i < m; i++)v.push_back(0);
	for (int i = 0; i < virus.size() - m; i++)v.push_back(1);

	do {
		int c[55][55] = { 0, };

		queue<tuple<int, int, int>>q;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				int x = virus[i].first;
				int y = virus[i].second;
				q.push({ x, y, 0 });
			}
		}

		while (!q.empty()) {
			int cx, cy, cs;
			tie(cx, cy, cs) = q.front();
			c[cx][cy] = cs;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (!inrange(nx, ny)) continue;
				if (arr[nx][ny] == 1) continue;
				if (c[nx][ny] != 0) continue;

				q.push({ nx,ny,cs + 1 });
			}
		}

		int val = 0;
		int check = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				val = max(val, c[i][j]);
				if (arr[i][j] == 0 || arr[i][j] == 2) {
					if (c[i][j] == 0) check = 1;
				}
			}
		}
		if(!check) ans = min(ans, val);

	} while (next_permutation(v.begin(), v.end()));


	
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	
	return 0;
}