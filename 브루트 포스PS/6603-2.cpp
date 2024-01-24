//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int arr[14];
//bool c[14];
//
//void go(int index, int start,int n)
//{
//	if (index == 6) {
//		for (int i = 1; i < 14; i++) {
//			if (c[i]) cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	for (int i = start; i <= n; i++) {
//		if (c[i]) continue;
//		c[i] = true; 
//		go(index + 1, i + 1, n);
//		c[i] = false;
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(nullptr), cout.tie(nullptr);
//
//	while (1) {
//		int n; cin >> n;
//		if (n == 0) break;
//		for (int i = 1; i <= n; i++) cin >> arr[i];
//
//		//go(0, 1,n);
//		cout << '\n';
//	}
//
//	return 0;
//}
