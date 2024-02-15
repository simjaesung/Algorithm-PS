#include<iostream>
#include<vector>
using namespace std;

int arr[55][15];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) cin >> arr[i][j];
	}

	int ans = 0;

	for (int i = 1; i <= 9; i++) {
		int score = 0;
		int turn = i, ing = 1; 
		int out = 0; vector<int>j;

		//한개의 이닝 당
		while (ing <= n) {
			
			if (out == 3) {
				out = 0;
				ing++; j.clear();
				
				cout <<"score: " << score << '\n';
				
				continue;
			}
			cout << ing << ' ' << turn << '\n';
			
			int val = 0;
			
			if (arr[ing][turn] == 1) val = 1;
			else if (arr[ing][turn] == 2) val = 2;
			else if (arr[ing][turn] == 3) val = 3;
			else if (arr[ing][turn] == 4) val = 4;
			else out++;

			if (turn == 4) val = arr[ing][1];

			if (val != 0) {
				j.push_back(0);
				for (int k = 0; k < j.size(); k++) {
					if (j[k] == -1) continue;

					j[k] += val;
					if (j[k] > 3) {
						score++;
						j[k] = -1;
					}
				}
			}

			turn = (turn + 1) % 10;
			if (turn == 0) turn += 2;
		}
		ans = max(score,ans);
	}
	
	cout << ans;
	return 0;
}