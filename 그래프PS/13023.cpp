//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int> arr[2005];
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int n, m; 
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++) {
//		int a, b; cin >> a >> b;
//		arr[a].push_back(b);
//		arr[b].push_back(a);
//	}
//
//	for (int A = 0; A < n; A++) {
//		for (int i = 0; i < arr[A].size(); i++) {
//			int B = arr[A][i]; //A�� ģ���� 1��
//
//			for (int j = 0; j < arr[B].size(); j++) {
//				if (A == arr[B][j]) continue;
//				int C = arr[B][j]; //B�� ģ�� �� �Ѹ�
//
//				for (int k = 0; k < arr[C].size(); k++) {
//					if (A == arr[C][k] || B == arr[C][k]) continue;
//					int D = arr[C][k]; //C�� ģ�� �� �Ѹ�
//
//					for (int l = 0; l < arr[D].size(); l++) {
//						if (A == arr[D][l] || B == arr[D][l] || C == arr[D][l]) continue;
//						//D�� ģ���߿� ABC�� ������ E
//						cout << 1;
//						return 0;
//					}
//				}
//			}
//		}
//	}
//	cout << 0;
//	return 0;
//}