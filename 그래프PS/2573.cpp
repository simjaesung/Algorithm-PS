#include<iostream>
using namespace std;

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

//문제에서 주어질 빙하의 범위
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
		//방문하지 않은 빙하 높이가 0 이상일 경우 방문해줘야함
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

	//빙하 별 주변 바다개수 추가
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
		
		ans++; //1년 후

		//바다 개수만큼 빙하 높이 줄여주기
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				arr[i][j][0] -= arr[i][j][1];
			}
		}

		//이후 
		int cnt = 0;
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (c[i][j] == 0 && arr[i][j][0] > 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}


		//dfs탐색 범위가 0개일 경우 모두 한번에 녹은 것
		if (cnt == 0) {
			ans = 0;
			break;
		}
		//1개 이상일 경우는 정답 요건에 충족
		if (cnt > 1) break;

		//바다개수 초기화
		for (int i = 0; i < 301; i++) {
			for (int j = 0; j < 301; j++)
				arr[i][j][1] = 0;
		}

		//줄어든 빙하를 기준으로 다시 주변 바다 개수 세어주기
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
