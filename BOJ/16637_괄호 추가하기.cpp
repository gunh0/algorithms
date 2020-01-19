#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 20
#define INF 987654321

int n, ans;
char map[MAX];
int bound[MAX];

// 두개의 정수와 한개의 연산자를 통해 사칙연산을 하여 결과를 반환하는 메소드
int calculate(int i, int j, char op) {
	switch (op) {
	case '+':
		return i + j;
	case '-':
		return i - j;
	case '*':
		return i * j;
	default:
		break;
	}
	return 0;
}

// 괄호를 포함한 수식의 결과를 반환하는 메소드
int getResult() {
	vector<string> v, nv;
	string str = "";

	// 괄호 우선 계산
	int i = 1;
	while (i <= n) {
		// 일반적인 정수나 연산자는 벡터에 바로 push
		if (bound[i] == 0) {
			str = map[i];
			v.push_back(str);
			i++;
		}
		// '(' 괄호가 포함된 정수라면 ??
		// 다음 노드인 연산자와 다다음 노드인 정수를 이용하여 사칙연산을 한 뒤, 벡터에 push
		else if (bound[i] & (1 << 1)) {
			int a = map[i] - '0';
			int b = map[i + 2] - '0';
			char op = map[i + 1];
			v.push_back(to_string(calculate(a, b, op)));
			i += 3;
		}
	}

	// 벡터에서 연산자를 꺼낸 뒤, 계산을 진행함
	int res = stoi(v[0]);
	for (int i = 1; i < v.size(); i += 2) {
		if (v[i] == "+") {
			res += stoi(v[i + 1]);
		}
		else if (v[i] == "-") {
			res -= stoi(v[i + 1]);
		}
		else if (v[i] == "*") {
			res *= stoi(v[i + 1]);
		}
	}

	return res;
}

void dfs(int ind) {
	// 괄호를 포함하여 연산의 결과를 얻어 최대값 갱신
	ans = max(ans, getResult());

	// 반복문을 통해 수식의 정수만 돌며
	// 해당 인덱스와 다음 인덱스에 괄호를 추가함
	for (int i = ind; i <= n; i += 2) {
		if (bound[i] == 0 && bound[i + 2] == 0 && i + 2 <= n) {
			bound[i] |= (1 << 1);
			bound[i + 2] |= (1 << 0);
			dfs(i + 2);
			bound[i] &= ~(1 << 1);
			bound[i + 2] &= ~(1 << 0);
		}
	}
}

int main(int argc, const char* argv[]) {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	ans = -INF;
	dfs(1);
	cout << ans << "\n";

	return 0;
}