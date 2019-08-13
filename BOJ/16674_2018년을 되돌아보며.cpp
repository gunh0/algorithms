#include <iostream>
using namespace std;

int main() {
	int cnt[5] = { 0, };
	bool chk[4] = { 0, };
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case '2':
			cnt[0] += 1;
			break;
		case '0':
			cnt[1] += 1;
			break;
		case '1':
			cnt[2] += 1;
			break;
		case '8':
			cnt[3] += 1;
			break;
		default:
			cnt[4] += 1;
		}
	}

	if (cnt[4])	chk[3] = true;	// 관련 없는 수
	else if (((cnt[0] == cnt[1]) && cnt[1] == cnt[2]) && cnt[2] == cnt[3])	chk[2] = true;	// 묶여있는 수
	else if (cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1 && cnt[3] >= 1)	chk[1] = true;
	else if (cnt[0] >= 1 || cnt[1] >= 1 || cnt[2] >= 1 || cnt[3] >= 1)	chk[0] = true;

	for (int i = 3; i >= 0; i--) {
		if (chk[i]) {
			if (i == 3) cout << 0;
			else if (i == 2) cout << 8;
			else cout << i + 1;
			break;
		}
	}
}