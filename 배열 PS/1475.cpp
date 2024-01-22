//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int ans,arr[10] = { 0 };
//	string num;
//	cin >> num;
//
//	for (auto& x : num) arr[x - '0']++;
//
//	arr[9] += arr[6]; arr[6] = 0;
//	ans = arr[9] % 2 + arr[9] / 2;
//	arr[9] = ans;
//	for (auto& x : arr) ans = max(ans,x);
//
//	cout << ans;
//
//	return 0;
//}