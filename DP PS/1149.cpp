//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	int m[1001][3];
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < 3; j++)
//			cin >> m[i][j];
//	}
//
//	for (int i = 2; i <= n; i++) {
//		m[i][0] += min(m[i - 1][1], m[i - 1][2]);
//		m[i][1] += min(m[i - 1][0], m[i - 1][2]);
//		m[i][2] += min(m[i - 1][1], m[i - 1][0]);
//	}
//
//	cout << min(m[n][0],min(m[n][1], m[n][2]));
//	return 0;
//}