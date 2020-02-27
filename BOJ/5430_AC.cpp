#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, n;
	cin >> T;
	cin.clear();
	cin.ignore(2, '\n');
	while (T--) {
		string p, string_arr;
		cin >> p >> n >> string_arr;

		deque<int> deq;

		if (n != 0) {
			int start = 1;
			for (int i = 1; i < string_arr.size(); ++i) {
				if (string_arr[i] == ',' || string_arr[i] == ']') {
					deq.emplace_back(stoi(string_arr.substr(start, i - start)));
					start = i + 1;
				}
			}
		}


		bool isFront = true;
		bool isError = false;
		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == 'R') {
				if (isFront) isFront = false;
				else isFront = true;
			}
			else if (p[i] == 'D') {
				if (deq.empty()) {
					isError = true;
					break;
				}
				if (isFront) deq.pop_front();
				else deq.pop_back();
			}
		}

		if (isError) cout << "error\n";
		else {
			if (deq.empty()) cout << "[]\n";
			else {
				int size = deq.size();
				if (isFront) {
					cout << '[' << deq[0];
					for (int i = 1; i < size; ++i) {
						cout << ',' << deq[i];
					}
				}
				else {
					cout << '[' << deq[size - 1];
					for (int i = size - 2; i >= 0; --i) {
						cout << ',' << deq[i];
					}
				}
				cout << "]\n";
			}
		}
	}

	return 0;
}