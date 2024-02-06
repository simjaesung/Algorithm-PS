#include<iostream>
#include<deque>
using namespace std;
int arr[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, w, l;
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++) cin >> arr[i];

	deque<int>d; 
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		while (1) {
			//다리 위에 트럭이 꽉 차있으면 앞에껄 빼내야함
			if (d.size() == w) {
				l += d.front();
				d.pop_front();
			}
			//앞에가 나가고 다음 트럭이 들어갈 수 있는 경우 break
			if (l >= arr[i]) break;

			//다음 트럭이 들어가지 못할 경우 0키로 그램 트럭을 올려
			//앞을 밀어냄..?
			d.push_back(0);
			cnt++;
		}

		d.push_back(arr[i]);
		l -= arr[i];
		cnt++;
	}

	//마지막 트럭이 다리위를 건너는 시간 추가
	cout << cnt + w;

	return 0;
}