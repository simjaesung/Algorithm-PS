#include<iostream>
#include<algorithm>
using namespace std;

char arr[6][6];
int check[6][6], v[6][6];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int p[25];

bool inrange(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}


int som, yeon, cnt, ans = 0;

void dfs(int x, int y)
{
	cnt++;
	if (arr[x][y] == 'S') som++;
	else yeon++;

	v[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!inrange(nx, ny)) continue;
		if(check[nx][ny] == 1 && v[nx][ny] == 0) dfs(nx, ny);
	}
}

int main()
{
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < 5; j++) {
			arr[i][j] = s[j];
		}
	}

	fill(p + 7, p + 25, 1);

	do {
		//check �迭 �ʱ�ȭ
		for (int i = 0; i < 6; i++)
			fill(check[i], check[i] + 6, 0);
		//�湮��� �ʱ�ȭ
		for (int i = 0; i < 6; i++)
			fill(v[i], v[i] + 6, 0);

		int sx,sy; 

		for (int i = 0; i < 25; i++) {
			if (p[i] == 0) {
				check[i / 5][i % 5] = 1;
				sx = i / 5;
				sy = i % 5;
			}
		}
		som = 0; yeon = 0; cnt = 0;
		dfs(sx, sy);
		if (cnt == 7) {
			cout << cnt << ' ' << yeon << ' ' << som << '\n';
		}
		if (cnt == 7 && yeon < 4) ans++;

	} while (next_permutation(p, p + 25));

	cout << ans;

	return 0;
}