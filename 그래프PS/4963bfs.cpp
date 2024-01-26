#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[55][55];
int c[55][55];

int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};
int w, h;

int inrange(int x, int y) {
	if (x >= 0 && x < h && y >= 0 && y < w)return 1;
	return 0;
}

void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	c[x][y] = 1;
	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			if (inrange(nextx, nexty)) {
				if (map[nextx][nexty] == 1 && c[nextx][nexty] == 0) {
					c[nextx][nexty] = 1;
					q.push(make_pair(nextx, nexty));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		for (int i = 0; i < 55; i++) fill(c[i], c[i] + 55, 0);

		cin >> w >> h;
		if (w == 0 && h == 0)break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)	cin >> map[i][j];
		}

		int ans = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && c[i][j] == 0) {
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}