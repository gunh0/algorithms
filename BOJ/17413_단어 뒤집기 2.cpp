#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);

	bool bracket = false;
	string temp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			if (temp.empty()) {
				temp += s[i];
				bracket = true;
			}
			else {
				reverse(temp.begin(), temp.end());
				cout << temp << '<';
				temp.clear();
				bracket = true;
			}
		}
		else if (s[i] == '>') {
			cout << temp << '>';
			bracket = false;
			temp.clear();
		}
		else if (s[i] == ' ') {
			if (bracket == true)
				temp += s[i];
			else {
				reverse(temp.begin(), temp.end());
				cout << temp << ' ';
				temp.clear();
			}
		}
		else {
			temp += s[i];
		}
	}

	reverse(temp.begin(), temp.end());
	cout << temp << ' ';

	return 0;
}