#include<iostream>
using namespace std;
int arr[25][25];
int mv[1005], topnum[1005], dice[10];
int n, m;
int le = 0, ri = 0;

//悼率, 辑率, 合率, 巢率 艾阑 嫐 拉搁


bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

//促澜 top捞 瞪 镑
void next(int move) 
{
	if (move == 1) {
		//421653
		int nxtdice[7] = { 0,dice[4],dice[2] ,dice[1] ,dice[6] ,dice[5] ,dice[3] };
		for (int i = 1; i <= 6; i++) dice[i] = nxtdice[i];
	}
	else if (move == 2) {
		//326154
		int nxtdice[7] = { 0,dice[3],dice[2] ,dice[6] ,dice[1] ,dice[5] ,dice[4] };
		for (int i = 1; i <= 6; i++) dice[i] = nxtdice[i];
	}
	else if (move == 3) {
		//513462
		int nxtdice[7] = { 0,dice[5],dice[1] ,dice[3] ,dice[4] ,dice[6] ,dice[2] };
		for (int i = 1; i <= 6; i++) dice[i] = nxtdice[i];
	}
	else {
		//263415
		int nxtdice[7] = { 0,dice[2],dice[6] ,dice[3] ,dice[4] ,dice[1] ,dice[5] };
		for (int i = 1; i <= 6; i++) dice[i] = nxtdice[i];
	}
	
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b, k;
	cin >> n >> m >> a >> b >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < k; i++) cin >> mv[i];

	int top = 1;
	//谅快肺 备弗 冉荐
	for (int i = 0; i < k; i++) {
		int nx, ny;
		//悼率
		if (mv[i] == 1) {
			nx = a; ny = b + 1;
		}
		//辑率
		else if (mv[i] == 2) {
			nx = a; ny = b - 1;
		}
		//合率
		else if (mv[i] == 3) {
			nx = a - 1; ny = b;
		}
		//巢率 (mv[i] == 4) 
		else {
			nx = a + 1; ny = b;
		}

		if (!inrange(nx, ny)) {
			topnum[i] = -1;
			continue;
		}

		a = nx; b = ny; next(mv[i]);
		topnum[i] = dice[1];

		if (arr[a][b] == 0) arr[a][b] = dice[6];
		else {
			dice[6] = arr[a][b];
			arr[a][b] = 0;
		}
		
	}
	
	for (int i = 0; i < k; i++) {
		if (topnum[i] != -1) cout << topnum[i] << '\n';
	}
	
	return 0;
}