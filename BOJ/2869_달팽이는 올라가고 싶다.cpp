#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, v;
	cin >> a >> b >> v;

	cout << (v - b - 1) / (a - b) + 1 << endl;

	return 0;
}

// �Ϸ翡 a-b �� v ��ŭ �̵�
// ��ǥ���� �������� -b ����
// �ᱹ v-b ��ŭ �̵�
// a-b �� ������������ �ʴ� ��츦 ���� -1�� +1 ����