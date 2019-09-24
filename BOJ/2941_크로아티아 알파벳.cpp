#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int i = 0, c = 0;
	string s;

	cin >> s;
	while (i < s.length()) {
		if (s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-')) i++;
		else if (s[i] == 'd') {
			if (s[i + 1] == '-') i++;
			else if (s[i + 1] == 'z' && s[i + 2] == '=') i += 2;
		}
		else if ((s[i] == 'l' || s[i] == 'n') && s[i + 1] == 'j') i++;
		else if ((s[i] == 's' || s[i] == 'z') && s[i + 1] == '=') i++;
		i++, c++;
	}
	cout << c << endl;

	return 0;
}