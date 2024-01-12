//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(nullptr), cout.tie(nullptr);
//	
//	vector<int>check(1000001);
//	vector<int>odd_num(1000001);
//	int odd_index = 0;
//
//	for (int i = 2; i <= 1000000; i++) {
//		if (!check[i]) {
//			if (i % 2 == 1) odd_num[odd_index++] = i;
//			for (int j = 2 * i; j <= 1000000; j += i) {
//				check[j] = 1;
//			}
//		}
//	}
//	
//	int len_odd = 0;
//	for (auto x : odd_num) {
//		if (x == 0) break;
//		else len_odd++;
//	}
//
//	int n, a, b, con;
//	while (cin >> n) {
//		if (n == 0) break;
//		con = 1;
//		for (int i = 0; i < len_odd; i++) {
//			if (!check[odd_num[i]]) {
//				a = odd_num[i];
//				if (!check[n - a]) {
//					con = 0;
//					b = n - a;
//					cout << n << " = " << a << " + " << b <<'\n';
//					break;
//				}
//			}
//		}
//		if(con)	cout << "Goldbach's conjecture is wrong.\n";
//	}
//	
//
//	return 0;
//}