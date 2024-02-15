#include<iostream>
using namespace std;
int n, l, r;
int arr[55][55], c[55][55], v[55][55];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int sum = 0, cnt = 0;

void dfs(int x, int y, int val) {
	c[x][y] = val;
	sum += arr[x][y]; cnt++;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (!inrange(nx, ny)) continue;
		if (c[nx][ny] != 0) continue;
		int dif = abs(arr[x][y] - arr[nx][ny]);
		if (dif >= l && dif <= r) dfs(nx, ny, val);
	}
}

//���� �� ����
void dfsY(int x, int y) {
	//�� ���ձ��� �湮
	v[x][y] = 1;
	arr[x][y] = sum / cnt;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (!inrange(nx, ny)) continue;
		//���ձ������� �湮
		if (c[nx][ny] != c[x][y]) continue;
		if (v[nx][ny] == 0) dfsY(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}

	int ans = 0;
	while (1) {
		for (int i = 0; i < n; i++) { 
			fill(c[i], c[i] + n, 0); 
			fill(v[i], v[i] + n, 0);
		}

		int val = 1; //���� �ٸ� ���� �˻�
		int check = 1; //���ձ����� �ִ��� ������ Ȯ��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum = 0, cnt = 0;
				if (c[i][j] == 0) {
					dfs(i, j, val++); //dfs�� ���� ǥ��
					if (cnt > 1) {
						//2�� �̻��� ���� ������ �� 
						// ��հ����� �� ����
						check = 0;
						dfsY(i, j);
					}
				}
			}
		}
		//���ձ��������� ����
		if (check) break;
		ans++;
	}
	
	cout << ans;
	
	return 0;
}