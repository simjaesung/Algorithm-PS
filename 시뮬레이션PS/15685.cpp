#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
int arr[105][105];

int main()
{
	int n; cin >> n;
	while (n--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<tuple<int, int,int>>v;
		v.push_back({ x,y,d });

		for (int i = 0; i <= g; i++) {
			int tmp = v.size() - 1;
			for (int k = tmp; k >= 0; k--) {
				int cx, cy, cd;
				tie(cx, cy, cd) = v[k];

				
				int nx = cx + dx[cd];
				int ny = cy + dy[cd];
				int nd = (cd + 1) % 4;
				

				v.push_back({ nx,ny,nd });
			}

		}

		for (int k = 0; k < v.size(); k++) {
			int cx, cy, d;
			tie(cx, cy, d) = v[k];
			arr[cx][cy] = 1;

			cout << "\n===============\n";
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) cout << arr[i][j] << ' ';
				cout << '\n';
			}
		}
		
	}

	return 0;
}