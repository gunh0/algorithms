#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct _INFO_
{
    char name[11];
    int kor;
    int eng;
    int math;
}INFO;

INFO info[100001];

bool comp(const INFO& a, const INFO& b)
{
    if (a.kor != b.kor)
        return a.kor > b.kor;

    else if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
    {
        if (strcmp(a.name, b.name) < 0)
            return true;
        return false;
    }

    else if (a.kor == b.kor && a.eng == b.eng)
        return a.math > b.math;

    else if (a.kor == b.kor)
        return a.eng < b.eng;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> info[i].name >> info[i].kor >> info[i].eng >> info[i].math;

    sort(info, info + n, comp);

    for (int i = 0; i < n; i++)
        printf("%s\n", info[i].name);

    return 0;
}