#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    long n;
    std::cin >> n;
    // �����ڸ������� ���
    long m = n;
    int digit = 0;
    while (m)
    {
        m /= 10;
        digit++;
    }
    // �������� �ּ� n - 9*n�� �ڸ��� ���� ����
    long begin = n - digit * 9;
    char s[10];
    long sum = 0;
    bool find = false;
    for (long i = begin; i <= n; ++i)
    {
        sprintf(s, "%ld", i);
        sum = i;
        for (int j = 0; j < strlen(s); ++j)
            sum += s[j] - '0';
        if (sum == n)
        {
            find = true;
            cout << i << "\n";
            break;
        }
    }
    if (find == false)	cout << "0\n";

    return 0;
}