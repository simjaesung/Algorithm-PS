//#include<iostream>
//using namespace std;
//
//int a[10]; bool check[10];
//
//void go(int index, int n, int m) 
//{
//	if (index == m) {
//		for (int i = 0; i < m; i++)
//			cout << a[i] <<' ';
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (check[i]) continue;
//		check[i] = true; a[index] = i;
//		go(index + 1, n, m);
//		check[i] = false;
//	}
//}
//
//int main()
//{
//	int M, N;
//	cin >> N >> M;
//
//	go(0, N, M);
//	
//	return 0;
//}