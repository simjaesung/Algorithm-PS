//#include<iostream>
//
//using namespace std;
//int gcd(int a, int b)
//{
//	if (a < b) {
//		int swap = a;
//		a = b;
//		b = swap;
//	}
//
//	while (b != 0) {
//		int r = a % b;
//		a = b;
//		b = r;
//	}
//	return a;
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(nullptr), cin.tie(nullptr);
//
//	int n, a, b;
//	cin >> n;
//
//	while (n--) {
//		cin >> a >> b;
//		cout << a * b / gcd(a, b) << '\n';
//	}
//	return 0;
//}