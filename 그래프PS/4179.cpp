#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int r, c;
char miro[1005][1005];
int JI[1005][1005];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int inrange(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c)return 1;
	return 0;
}

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;

	queue<pair<int, int>>q;

	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			miro[i][j] = s[j];
			//지훈이일 경우 지훈이 위치를 큐 삽입 + 시작 위치 저장
			if (miro[i][j] == 'J') {
				q.push(make_pair(i, j));
				JI[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (miro[i][j] == '#') continue;
			//불일 경우 그 위치를 지훈이 다음으로 큐에 삽입
			if (miro[i][j] == 'F') q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				//벽인 경우
				if (miro[nx][ny] == '#') continue;

				//지훈이일 경우 빈 공간으로 다 보내주기
				else if (miro[cx][cy] == 'J') {
					if (miro[nx][ny] == '.' && JI[nx][ny] == 0) {
						JI[nx][ny] = JI[cx][cy] + 1;
						miro[nx][ny] = 'J';
						q.push(make_pair(nx, ny));
					}
				}
				//불일 경우 빈 공간이거나 지훈이인 경우 태우기
				else if (miro[cx][cy] == 'F') {
					if (miro[nx][ny] == '.' || miro[nx][ny] == 'J') {
						miro[nx][ny] = 'F';
						q.push(make_pair(nx, ny));
					}
				}
			}
			else {
				//다음 가는 공간에 미로 바깥일 때, 탈출 성공
				if (miro[cx][cy] == 'J') {
					cout << JI[cx][cy];
					return 0;
				}
			}
		}
		//딱히 의미 없음
		if (miro[cx][cy] == 'J') miro[cx][cy] == '.';
	}
	cout << "IMPOSSIBLE";
	return 0;
}
