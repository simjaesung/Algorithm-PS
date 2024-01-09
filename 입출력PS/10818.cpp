//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	int* arr = new int[n * sizeof(int)];
//
//	for (int i = 0; i < n; i++) {
//		int val;
//		cin >> val;
//		arr[i] = val;
//	}
//
//	int max(arr[0]); 
//	int min(arr[0]);
//
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > max)
//			max = arr[i];
//		if (arr[i] < min)
//			min = arr[i];
//	}
//	
//	cout << min << " " << max;
//	
//	delete[] arr;
//	return 0;
//}