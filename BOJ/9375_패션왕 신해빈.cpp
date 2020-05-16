#include <iostream>
#include <map>

using namespace std;

int main() {

	int T, N, i, j, mul;
	string temp, key;
	map <string, int> m;
	pair<map<string, int>::iterator, bool > pr;

	cin >> T;

	for (i = 0; i < T; i++) {
		m.clear();
		mul = 1;
		cin >> N;
		for (j = 0; j < N; j++) {
			cin >> temp >> key;
			pr = m.insert(pair <string, int>(key, 1));
			if (!pr.second) m[key]++;
		}
		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
			mul = mul * (it->second + 1);
		}
		cout << mul - 1 << endl;
	}

	return 0;
}