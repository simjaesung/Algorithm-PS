//#include<iostream>
//using namespace std;
//
//char game[55][55];
//int c[55][55];
//int n, m, cx, cy, check = 0;
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//
//bool inrange(int x, int y) {
//	return x >= 0 && x < n && y >= 0 && y < m;
//}
//
//void dfs(int x, int y, char color,int cnt)
//{
//	cnt++;
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (!inrange(nx, ny)) continue;
//		if (game[nx][ny] == color) {
//			if (c[nx][ny] == 1 && nx == cx 
//				&& ny == cy && cnt >= 4) {
//				check = 1;
//				return;
//			}
//			else if (c[nx][ny] == 0) {
//				c[nx][ny] = 1;
//				dfs(nx, ny, color, cnt);
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		string s; cin >> s;
//		for (int j = 0; j < s.length(); j++) {
//			game[i][j] = s[j];
//		}
//	}
//
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++) {
//			if (c[i][j] == 0) {
//				c[i][j] = 1;
//				cx = i; cy = j;
//				int cnt = 0;
//				dfs(i, j, game[i][j], cnt);
//				if(check == 1){
//					cout << "Yes";
//					return 0;
//				}
//				for (int k = 0; k < 55; k++)
//					fill(c[k], c[k] + 55, 0);
//			}
//		}
//	}
//	cout << "No";
//	
//	return 0;
//}
