/*
������ ������ �������� �����濡 �����Ͽ����ϴ�.
�� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.
�����濡 ������ �������� �̸��� ��� �迭 participant��
������ �������� �̸��� ��� �迭 completion�� �־��� ��,
�������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.
*/

#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	return answer;
}

int main()
{
	int par = 0, com = 0;
	string tmp;
	vector<string> participant;
	vector<string> completion;
	cout << "participant : ";
	cin >> par;
	for (int i = 0; i < par; i++)
	{
		cin >> tmp;
		participant.push_back(tmp);
	}
	cout << "completion : ";
	cin >> com;
	for (int i = 0; i < com; i++)
	{
		cin >> tmp;
		completion.push_back(tmp);
	}
}