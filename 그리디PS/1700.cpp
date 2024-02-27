#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<queue<int>>v(105); //�� ���ǵ��� ���� ť
vector<int>cs; //�ܼ�Ʈ�� �����ִ°� 
int arr[105];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> arr[i];
		//������ �Ҵ�� ������ push
		v[arr[i]].push(i);
	}
	int ans = 0;

	for (int i = 1; i <= k; i++) {
		if (cs.size() < n) {
			//�̹� �����ִ°��� Ȯ�� 
			int check = 0;
			for (int j = 0; j < cs.size(); j++) {
				if (arr[i] == cs[j]) check = 1;
			}
			if (!check) cs.push_back(arr[i]);
			v[arr[i]].pop();
		}
		else{
			//�ܼ�Ʈ�� �����ִ��� Ȯ���ϱ�
			int check = 0;
			for (int j = 0; j < cs.size(); j++) {
				if (arr[i] == cs[j]) check = 1;
			}
			if (check) {
				v[arr[i]].pop();
				continue;
			}

			int maxturn = 0; //���� �ʰ� ����ϴ� ����
			int maxval = 0; //�� ������ ��ȣ
			for (int j = 0; j < cs.size(); j++) {
				//���̻� ���� ���� ���� ��
				if (v[cs[j]].empty()) {
					maxval = cs[j];
					break;
				}
				//���� �ʰ� �Ҵ� �޴� ���� Ȯ�� 
				else if (v[cs[j]].front() > maxturn) {
					maxval = cs[j];
					maxturn = v[cs[j]].front();
				}
			}

			//�ܼ�Ʈ �̱�
			for (int j = 0; j < cs.size(); j++) {
				if (cs[j] == maxval) {
					cs[j] = arr[i];
					v[arr[i]].pop();
					ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}