#include<iostream>
using namespace std;

int arr[10][10], arrc[10][10], cc[10][10];
int sele[5], c[100];

int n, m, ans = 0;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) 
{
	cc[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!inrange(nx, ny)) continue;
		if (arrc[nx][ny] == 1) continue;

		if(cc[nx][ny] == 0) dfs(nx, ny);
	}
}


void go(int select, int start)
{
	if (select == 3){
		//연구소 원본 복구
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arrc[i][j] =  arr[i][j];
			}
		}

		//벽 세우기
		//값은 0 ~ n*m 중 3개를 택함
		for (int i = 0; i < 3; i++) {
			int k = sele[i];
			if (arrc[k / m][k % m] != 0) return;
			arrc[k / m][k % m] = 1;
		}

		//바이러스 dfs
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arrc[i][j] == 2 && cc[i][j] == 0) dfs(i, j);
			}
		}

		int safe = 0;
		//바이러스가 퍼지지않은 벽이아닌 공간
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cc[i][j] == 0 && arrc[i][j] != 1) safe++;
			}
		}

		ans = max(ans, safe);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cc[i][j] = 0;
			}
		}

		return;
	}

	for (int i = start; i < n * m; i++) {
		if (c[i]) continue;
		sele[select] = i; c[i] = 1;
		go(select + 1, i);
		c[i] = 0;
	}

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	go(0, 0);

	cout << ans;
	return 0;
}