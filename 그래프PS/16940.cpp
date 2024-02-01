#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int>arr[100005];
vector<int>bfs[100005];
int c[100005], check[100005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b; 
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int k = 1; k <= n; k++) cin >> check[k];

	if (check[1] != 1) {
		cout << 0;
		return 0;
	}

	queue<pair<int, int>>q;
	q.push(make_pair(1, 1));
	while (!q.empty()){
		int cx = q.front().first;
		int idx = q.front().second;
		q.pop(); c[cx] = 1;
		
		bfs[idx].push_back(cx);
		for (auto nx : arr[cx]) {
			if (c[nx] == 0) {
				q.push(make_pair(nx, idx + 1));
			}
		}
	}
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (bfs[i].size() == 0) break;
		for (int j = 0; j < bfs[i].size(); j++) {
			int tmp = 0;
			for (int k = cnt; k < cnt + bfs[i].size(); k++) {
				if (check[k] == bfs[i][j]) tmp = 1;
			}
			if (!tmp) {
				cout << 0; 
				return 0;
			}
		}
		cnt += bfs[i].size();
	}

	cout << 1;
	return 0;
}