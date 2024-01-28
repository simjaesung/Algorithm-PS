#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[105][105], c[105][105], b[105][105];
int n;

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y, int cnt)
{
	c[x][y] = cnt;
	queue<pair<int,int>>q; 
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				if (arr[nx][ny] == 1 && c[nx][ny] == 0) {
					c[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int bfs2(int x, int y, int land)
{
	b[x][y] = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny) && b[nx][ny] == 0) {
				//������ ���
				
				if (arr[nx][ny] == 1) {
					//�����ε� �ٸ� ����̸�(�ٸ��ϼ�)
					if (c[nx][ny] != land) {
						return b[cx][cy];
					}
				}
				//�ٴ��� ���
				else {
					b[nx][ny] = b[cx][cy] + 1;
					q.push(make_pair(nx, ny));
				}
				
			}
		}
	}
	return -1;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	//��� �� ��ȣ �ް��ֱ� 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && c[i][j] == 0)
				bfs(i, j, ++cnt);
		}
	}

	int ans = 200;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) { 
				//�ٴ��̰� ��濡 ������ ������
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (inrange(nx, ny) && arr[nx][ny] == 1) {
						//�����ִ� ª�� �ٸ����� ã��
						int val = bfs2(i, j, c[nx][ny]);
						if (val != -1)ans = min(ans, val);
						

						//�ٸ� ���۵� �ʱ�ȭ
						for (int s = 0; s < 105; s++)
							fill(b[s], b[s] + 105, 0);
					}
				}
			}
		}

	}
	cout << ans;
		
	
	return 0;
}

/*cout << "================\n";
						cout << i << ' ' << j << "\n";
						for (int k = 0; k < n; k++) {
							for (int l = 0; l < n; l++) {
								cout << b[k][l] << ' ';
							}
							cout << '\n';
						}*/