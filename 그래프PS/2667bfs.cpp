#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int arr[30][30];
int c[30][30] = { 0 };

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n;

int inrange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return 1;
	return 0;
}

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	c[x][y] = cnt;
	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			if (inrange(next_x, next_y)) {
				if (arr[next_x][next_y] == 1 && c[next_x][next_y] == 0) {
					c[next_x][next_y] = cnt;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) 
			arr[i][j] = s[j] - '0';
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && c[i][j] == 0)
				bfs(i, j, ++cnt);
		}
	}

	cout << cnt << '\n';

	vector<int>v(cnt);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] != 0) v[c[i][j] - 1]++;
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < cnt; i++) cout << v[i] << '\n';
	return 0;
}