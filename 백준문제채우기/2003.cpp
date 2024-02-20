//#include<iostream>
//using namespace std;
//int sum[10005];
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m; cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> sum[i]; 
//		sum[i] += sum[i - 1];
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < i; j++) {
//			if (sum[i] - sum[j] == m) ans++; 
//		}
//	}
//
//	cout << ans;
//	return 0;
//}