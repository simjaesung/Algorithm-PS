#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int>arr[3005];
int c[3005], cir[3005];
int check;
//간선, 거리, 순환 여부

void dfs(int i, int x) 
{
	c[x] = 1;
	for (int s = 0; s < arr[x].size(); s++) {
		int cx = arr[x][s];
		if (cx != x) {
			if (cx == i) check = 1;
			if (c[cx] == 0) dfs(i, cx);
		}
	}
}


int main()
{
	int n; cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			fill(c, c + 3005, 0);
			check = 0; c[i] = 1;
			dfs(i, arr[i][j]);
			if (check) cir[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << cir[i] << ' ';
	
	return 0;
}
