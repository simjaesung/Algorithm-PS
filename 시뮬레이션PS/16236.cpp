#include<iostream>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;
int n;
int sx, sy, ssize = 2; //�Ʊ��� ��ġ�� ����
int arr[25][25], c[25][25];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y)); c[x][y] = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inrange(nx, ny)) continue;

			//������� ũ�Ⱑ Ŭ ���
			if (arr[nx][ny] > ssize) continue;

			//�̹� �湮���� ���
			if (c[nx][ny] != -1) continue;
			c[nx][ny] = c[cx][cy] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				//ó�� �Ʊ����� ��ġ
				sx = i, sy = j;
			}
		}
	}

	int eat = 0, ans = 0;
	while (1) {
		for (int i = 0; i < n; i++) fill(c[i], c[i] + n, -1);

		//�ٴ� �� �ִ� ���� Ž��
		bfs(sx, sy);

		int dist = INT_MAX;

		//����� ���� ��ġ
		int nsx = sx, nsy = sy;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// ���̰� ã��
				// ��ĭ�� �ƴϸ鼭 ����� ���� ��� ���� �� ���� �����ִ� ���̸�
				// ����� 9�϶� �������� ����
				if (arr[i][j] != 0 && arr[i][j] < ssize && c[i][j] != -1) {
					if (arr[i][j] != 9 && dist > c[i][j]) {
						dist = c[i][j];
						nsx = i, nsy = j;
					}
				}
			}
		}
		//��ġ�� ���� ��ġ�� ���� ��� ���� ����Ⱑ ���� ��
		if (nsx == sx && nsy == sy) break;
		else {
			arr[nsx][nsy] = 0;
			swap(arr[sx][sy], arr[nsx][nsy]);
			sx = nsx; sy = nsy;
			
			eat++;
			if (eat == ssize) {
				ssize++;
				eat = 0;
			}
			ans+= dist;
		}
	}
	cout << ans;
	
	return 0;
}