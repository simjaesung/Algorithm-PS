//#include<iostream>
//#include<math.h>
//
//using namespace std;
//
//int D[100001] = { 1 };
//int S[100001] = { 1 };
//
//int main()
//{
//	int n; 
//	cin >> n;
//
//	D[0] = 1, D[1] = 2;
//	S[0] = D[0], S[1] = D[0] + D[1];
//
//	for (int i = 2; i <= n; i++) {
//		D[i] = D[i - 1] + 2*S[i - 2];
//		S[i] = S[i - 1] + D[i];
//		
//		D[i] %= 9901;
//		S[i] %= 9901;
//	}
//		
//	cout << S[n];
//	return 0;
//}