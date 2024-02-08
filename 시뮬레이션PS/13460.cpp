#include<iostream>
using namespace std;

int xb, yb, xr, yr, xo, yo;
int pxb, pyb, pxr, pyr;
int n, m;

char arr[12][12];
//0 : 남쪽 1:북쪽 2: 동쪽 3:서쪽
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int root[12];

bool inrange(int x, int y) {
	return  x >= 0 && x < n && y >= 0 && y < m;
}

void moveR(int dir)
{
	if (dir == 0) {
		while (xr < n) {
			if (arr[xr + 1][yr] != '#' && arr[xr + 1][yr] != 'R') {
				xr++;
			}
			else break;
		}
	}
	//북쪽
	else if (dir == 1) {
		while (xr > 0) {
			if (arr[xr - 1][yr] != '#' && arr[xr - 1][yr] != 'R') {
				xr--;
			}
			else break;
		}
	}
	//동
	else if (dir == 2) {
		while (yr < m) {
			if (arr[xr][yr + 1] != '#' && arr[xr][yr + 1] != 'R') {
				yr++;
			}
			else break;
		}

	}
	//서
	else if (dir == 3) {
		while (yr > 0) {
			if (arr[xr][yr - 1] != '#' && arr[xr][yr - 1] != 'R') {
				yr--;
			}
			else break;
		}
	}
	return;
}


void moveB(int dir)
{
	//남
	if (dir == 0) {
		while (xb < n) {
			if (arr[xb + 1][yb] != '#' && arr[xb + 1][yb] != 'R') {
				xb++;
			}
			else break;
		}
	}
	//북쪽
	else if (dir == 1) {
		while (xb > 0) {
			if (arr[xb - 1][yb] != '#' && arr[xb - 1][yb] != 'R') {
				xb--;
			}
			else break;
		}
	}
	//동
	else if (dir == 2) {
		while (yb < m) {
			if (arr[xb][yb + 1] != '#' && arr[xb][yb + 1] != 'R') {
				yb++;
			}
			else break;
		}

	}
	//서
	else if (dir == 3) {
		while (yb > 0) {
			if (arr[xb][yb - 1] != '#' && arr[xb][yb - 1] != 'R') {
				yb--;
			}
			else break;
		}
	}
	return;
}


void go(int move)
{
	if (move == 10) {
		for (int i = 0; i < 10; i++) {
			cout << root[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < 4; i++) {
		//B의 주변
		int nxr = xr + dx[i];
		int nyr = yr + dy[i];
		if (inrange(nxr, nyr) && arr[nxr][nyr] != '#') {
			pxb = xb; pyb = yb;
			pxr = xr; pyr = yr;

			root[move] = i;
			//남
			if (i == 0) {
				if (xb < xr) {
					//r먼저 굴려야함
					moveR(0);
					moveB(0);
				}
				else {
					moveB(0);
					moveR(0);
				}
			}
			//북
			else if (i == 1) {
				if (xb < xr) {
					//b먼저 굴려야함
					moveB(1);
					moveR(1);
				}
				else {
					moveR(1);
					moveB(1);
				}
			}
			//동
			else if (i == 2) {
				if (yb < yr) {
					//r먼저 굴려야함
					moveR(2);
					moveB(2);
				}
				else {
					moveB(2);
					moveR(2);
				}
			}
			//서
			else {
				if (yb < yr) {
					//b먼저 굴려야함
					moveB(3);
					moveR(3);
				}
				else {
					moveR(3);
					moveB(3);
				}
			}

			go(move + 1);
			xb = pxb; yb = pyb; xr = pxr; yr = pyr;
		}
	}
}


int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				xb = i; yb = j;
			}
			if (arr[i][j] == 'R') {
				xr = i; yr = j;
			}
			if (arr[i][j] == 'O') {
				xo = i; yo = j;
			}
		}
	}

	go(0);



	return 0;
}