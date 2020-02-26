#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {

	while (1) {
		char input[101];
		cin.getline(input, 101);

		if (!strcmp(input, ".")) break;

		stack <char> s;
		int flag = 0;

		for (int i = 0; i < strlen(input); i++) {
			if (input[i] == '(' || input[i] == '[') s.push(input[i]);

			else if (input[i] == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else { cout << "no\n"; flag = 1; break; }
			}

			else if (input[i] == ']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else { cout << "no\n"; flag = 1; break; }
			}
		}

		if (flag) continue;

		if (!s.empty()) cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}