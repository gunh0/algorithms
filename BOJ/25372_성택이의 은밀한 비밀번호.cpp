#include <iostream>
#include <string>

using namespace std;

bool isValidPassword(const string &password)
{
    int length = password.length();

    // 비밀번호 길이가 6자리 이상 9자리 이하인지 확인
    if (length < 6 || length > 9)
    {
        return false;
    }

    // 숫자와 영어 대소문자로만 구성되어 있는지 확인
    for (char ch : password)
    {
        if (!isdigit(ch) && !isalpha(ch))
        {
            return false;
        }
    }

    // 모든 조건을 만족하면 유효한 비밀번호로 판단
    return true;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string password;
        cin >> password;

        if (isValidPassword(password))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
