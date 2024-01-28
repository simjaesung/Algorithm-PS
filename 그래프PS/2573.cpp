#include<iostream>
using namespace std;

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

//�������� �־��� ������ ����
bool inrange(int x, int y) {
	return x > 0 && x < n - 1 && y > 0 && y < m - 1;
}

int arr[301][301][2];
int c[301][301];

void dfs(int x, int y) 
{
	c[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//�湮���� ���� ���� ���̰� 0 �̻��� ��� �湮�������
		if (inrange(nx, ny) && c[nx][ny] == 0 && arr[nx][ny][0] > 0) 
			dfs(nx, ny);
	}
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j][0];
		}
	}

	//���� �� �ֺ� �ٴٰ��� �߰�
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (arr[nx][ny][0] == 0) arr[i][j][1]++;
			}
		}
	}

	int ans = 0;
	
	while (1) {
		for (int i = 0; i < 301; i++)
			fill(c[i], c[i] + 301, 0);
		
		ans++; //1�� ��

		//�ٴ� ������ŭ ���� ���� �ٿ��ֱ�
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				arr[i][j][0] -= arr[i][j][1];
			}
		}

		//���� 
		int cnt = 0;
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (c[i][j] == 0 && arr[i][j][0] > 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}


		//dfsŽ�� ������ 0���� ��� ��� �ѹ��� ���� ��
		if (cnt == 0) {
			ans = 0;
			break;
		}
		//1�� �̻��� ���� ���� ��ǿ� ����
		if (cnt > 1) break;

		//�ٴٰ��� �ʱ�ȭ
		for (int i = 0; i < 301; i++) {
			for (int j = 0; j < 301; j++)
				arr[i][j][1] = 0;
		}

		//�پ�� ���ϸ� �������� �ٽ� �ֺ� �ٴ� ���� �����ֱ�
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (arr[nx][ny][0] <= 0) arr[i][j][1]++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}


//cout << "=====================\n";
//for (int i = 1; i < n - 1; i++) {
//	for (int j = 1; j < m - 1; j++) {
//		cout << arr[i][j][0] << ' ';
//	}
//	cout << '\n';
//}*/
