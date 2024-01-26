#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int c[305][305];
int dx[] = { -1,-2,-2,-1,1,2,2, 1 };
int dy[] = { -2,-1, 1, 2,2,1,-1,-2 };

int l;

int inrange(int x, int y) {
	if (x >= 0 && x < l && y >= 0 && y < l) return 1;
	return 0;
}


int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		for (int i = 0; i < 305; i++)
			fill(c[i], c[i] + 305, 0);

		cin >> l;

		//시작점과 끝점
		int sx, sy, ex, ey;

		cin >> sx >> sy;
		cin >> ex >> ey;
		
		queue<pair<int, int>>q;
		q.push(make_pair(sx, sy));
		c[sx][sy] = 1;

		while (!q.empty()) {
			//현재 위치
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				//다음 위치
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (inrange(nx, ny)) {
					//아직 이동하지 않은 곳이라면 현재 위치에서 +1
					if (c[nx][ny] == 0) {
						c[nx][ny] = c[cx][cy] + 1;
						q.push(make_pair(nx, ny));
					}
					//한번 이상 거쳐간 곳인데, 현재 위치 +1 보다 큰 값일 때
					else {
						if (c[nx][ny] > c[cx][cy] + 1) {
							c[nx][ny] = c[cx][cy] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
		cout << c[ex][ey] - 1 << '\n';
	}


	return 0;
}
