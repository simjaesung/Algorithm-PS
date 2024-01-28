//#include<iostream>
//#include<tuple>
//#include<queue>
//#include<limits.h>
//
//using namespace std;
//int k, w, h;
//int dx[] = { 0,0,1,-1 };
//int dy[] = { 1,-1,0,0 };
//int dhx[] = { -1,-2,-2,-1,1,2,2,1 };
//int dhy[] = { -2,-1,1,2,2,1,-1,-2 };
//
//bool inrange(int x, int y) {
//	return x >= 0 && x < h && y >= 0 && y < w;
//}
//
//int arr[205][205];
//int c[205][205][35];
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> k;
//	cin >> w >> h;
//	//지형 입력
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++)
//			cin >> arr[i][j];
//	}
//
//	//방문 초기화
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			for (int s = 0; s <= k; s++) {
//				c[i][j][s] = -1;
//			}
//		}
//	}
//
//	queue<tuple<int, int, int>>q;
//	q.push({ 0,0,0 });
//	c[0][0][0] = 0;
//	while (!q.empty()) {
//		//ch는 현재까지 말을 따라한 횟수
//		int cx, cy, ch;
//		tie(cx, cy, ch) = q.front(); 
//		q.pop();
//
//		//말을 따라한 횟수가 남을 경우
//		if (ch < k) {
//			for (int i = 0; i < 8; i++) {
//				int nx1 = cx + dhx[i];
//				int ny1 = cy + dhy[i];
//				int nh1 = ch + 1;
//
//				if (inrange(nx1, ny1) && arr[nx1][ny1] == 0 && c[nx1][ny1][nh1] == -1) {
//					c[nx1][ny1][nh1] = c[cx][cy][ch] + 1;
//					q.push({ nx1,ny1,nh1 });
//				}
//			}
//		}
//		
//		// 그냥 이동
//		for (int j = 0; j < 4; j++) {
//			int nx2 = cx + dx[j];
//			int ny2 = cy + dy[j];
//
//			if (inrange(nx2, ny2) && arr[nx2][ny2] == 0 && c[nx2][ny2][ch] == -1) {
//				c[nx2][ny2][ch] = c[cx][cy][ch] + 1;
//				q.push({ nx2,ny2,ch });
//			}
//		}
//	}
//
//	int ans = INT_MAX;
//	for (int s = 0; s <= k; s++) {
//		int val = c[h - 1][w - 1][s];
//		if (val != -1) ans = min(ans, val);
//	}
//	if (ans == INT_MAX) cout << -1;
//
//	else cout << ans;
//	return 0;
//}



/*for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			for (int s = 0; s <= k; s++) {
				cout <<"i: " << i << " j: " << j << " s: " <<s <<" = " << c[i][j][s] << "/";
			}
			cout << '\n';
		}
		cout << '\n';

	}*/
