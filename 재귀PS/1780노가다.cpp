//#include<iostream>
//using namespace std;
//
//int arr[2200][2200];
//int ans[3];
//
//bool check(int a1, int b1, int a2, int b2) {
//	int val = arr[a1][b1];
//	for (int i = a1; i <= a2; i++) {
//		for (int j = b1; j <= b2; j++) {
//			if (val != arr[i][j]) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
////(a1, b1) ~ (a2, b2)를 탐색하는
//void cut(int a1, int b1, int a2, int b2)
//{
//	if (check(a1, b1, a2, b2)) {
//		ans[arr[a1][b1] + 1] += 1; 
//		return;
//	}
//	//한변의 길이
//
//	int v = (a2 - a1 + 1) / 3;
//
//	cut(a1, b1, a1 + v - 1, b1 + v - 1);
//	cut(a1, b1 + v, a1 + v - 1, b1 + v * 2 - 1);
//	cut(a1, b1 + v * 2, a1 + v - 1, b1 + v * 3 - 1);
//
//	cut(a1 + v, b1, a1 + 2 * v - 1, b1 + v - 1);
//	cut(a1 + v, b1 + v, a1 + 2 * v - 1, b1 + 2 * v - 1);
//	cut(a1 + v, b1 + 2 * v, a1 + 2 * v - 1, b1 + 3 * v - 1);
//
//	cut(a1 + 2 * v, b1, a1 + 3 * v - 1, b1 + v - 1);
//	cut(a1 + 2 * v, b1 + v, a1 + 3 * v - 1, b1 + 2 * v - 1);
//	cut(a1 + 2 * v, b1 + 2 * v, a1 + 3 * v - 1, b1 + 3 * v - 1);
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n; cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	cut(1, 1, n, n);
//
//	for (int k = 0; k < 3; k++)
//		cout << ans[k] << '\n';
//	
//	return 0;
//}