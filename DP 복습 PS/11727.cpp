//#include<iostream>
//using namespace std;
//
//int d[1005];
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	d[1] = 1; d[2] = 3;
//	for (int i = 3; i <= 1000; i++)
//		d[i] = (d[i - 2] * 2 + d[i - 1]) % 10007;
//
//	int n; cin >> n;
//	cout << d[n];
//	return 0;
//}