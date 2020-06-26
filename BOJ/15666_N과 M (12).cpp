#include<algorithm>
#include<iostream>
using namespace std;

int n, m, num[8], result[8];

// �Է¹��� n���� ���� �߿��� ����� ������ �Ȱ��� ������
// ���� �ʰ� m���� ���� ������ִ� �Լ�
void getResult(int count, int start) {

	// m���� ����ٸ� ����մϴ�
	if (count == m) {
		for (int i = 0; i < m; i++)
			cout << result[i] << ' ';
		cout << '\n';
		return;
	}
	int prev_num = -1;  // �ٷ� ������ ����� ���� �����ϴ� ����

	// start���� n-1������ �ε��� �� m���� ����
	for (int i = start; i < n; i++) {

		// �ߺ��Ǵ� ������ ������� �ʱ����� �ٷ� ������
		// ����� ���� ���� �ʰ�, �񳻸��������� ����ϱ� ����
		// �׻� ����� ������ ũ�ų� ���� ���� ���Բ� i�� ���ڷ� �Ѱ���
		if (prev_num != num[i]) {
			result[count] = num[i];
			prev_num = num[i];
			getResult(count + 1, i);
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	// ������ ���� ������ ����ؾ� �ϹǷ�
	// �Է��� �ް� ������������ ����
	sort(num, num + n);

	getResult(0, 0);
	return 0;
}
