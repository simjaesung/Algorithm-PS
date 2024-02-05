#include<iostream>
using namespace std;
int arr[25][25];
int mv[1005], topnum[1005], dice[10];
int n, m;

//동쪽, 서쪽, 북쪽, 남쪽 갔을 떄 윗면
int top1[] = { 4,3,5,2 };
int top2[] = { 4,3,1,6 };
int top3[] = { 1,6,5,2 };
int top4[] = { 1,6,2,5 };
int top5[] = { 4,3,6,1 };
int top6[] = { 4,3,2,5 };

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

//다음 top이 될 곳
int next(int top, int move) 
{
	if (top == 1) {
		return top1[move - 1];
	}
	else if (top == 2) {
		return top2[move - 1];
	}
	else if (top == 3){
		return top3[move - 1];
	}
	else if (top == 4) {
		return top4[move - 1];
	}
	else if (top == 5) {
		return top5[move - 1];
	}
	//if (top == 6)
	else {
		return top6[move - 1];
	}
}


int main()
{
	int a, b, k;
	cin >> n >> m >> a >> b >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < k; i++) cin >> mv[i];

	int top = 1;

	for (int i = 0; i < k; i++) {
		int nx, ny, nexttop;
		//동쪽
		if (mv[i] == 1) {
			nx = a; ny = b + 1; 
			nexttop = next(top, 1);
		}
		//서쪽
		else if (mv[i] == 2) {
			nx = a; ny = b - 1; 
			nexttop = next(top, 2);
		}
		//북쪽
		else if (mv[i] == 3) {
			nx = a - 1; ny = b; 
			nexttop = next(top, 3);
		}
		//남쪽 (mv[i] == 4) 
		else {
			nx = a + 1; ny = b; 
			nexttop = next(top, 4);
		}

		if (!inrange(nx, ny)) {
			topnum[i] = -1;
			continue;
		}

		a = nx; b = ny; top = nexttop;
		cout << "top : " << top << '\n';
		if (arr[a][b] == 0) {
			arr[a][b] = dice[7 - top];
		}
		else {
			dice[7 - top] = arr[a][b];
			arr[a][b] = 0;
		}

		topnum[i] = dice[top];
	}
	
	for (int i = 0; i < k; i++) {
		if (topnum[i] != -1) cout << topnum[i] << '\n';
	}
	
	return 0;
}