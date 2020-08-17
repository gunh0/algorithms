#include <algorithm>
#include <iostream>
#include <map>

#define fst first
#define snd second

using namespace std;

map<string, int> m;
struct abc {
	int x, y;
	double w, d, l;
} a[6];

int s[4];
double r[4];
pair<int, int> t[4];

void go(int n, double p) {
	if (n == 6) {
		for (int i = 0; i < 4; i++) {
			t[i].fst = s[i];
			t[i].snd = i;
		}
		sort(t, t + 4);
		int A = t[0].fst, B = t[1].fst, C = t[2].fst, D = t[3].fst;
		int a = t[0].snd, b = t[1].snd, c = t[2].snd, d = t[3].snd;
		if (B != C) {
			r[c] += p; r[d] += p;
		}
		else if (A == B && C == D) {
			r[a] += p / 2.0; r[b] += p / 2.0;
			r[c] += p / 2.0; r[d] += p / 2.0;
		}
		else if (A == B) {
			r[a] += p / 3.0; r[b] += p / 3.0;
			r[c] += p / 3.0; r[d] += p;
		}
		else if (C == D) {
			r[b] += p * 2.0 / 3.0; r[c] += p * 2.0 / 3.0;
			r[d] += p * 2.0 / 3.0;
		}
		else {
			r[b] += p / 2.0; r[c] += p / 2.0;
			r[d] += p;
		}
		return;
	}

	int x = a[n].x, y = a[n].y;

	s[x] += 3;
	go(n + 1, p * a[n].w);
	s[x] -= 3;

	s[x] += 1; s[y] += 1;
	go(n + 1, p * a[n].d);
	s[x] -= 1; s[y] -= 1;

	s[y] += 3;
	go(n + 1, p * a[n].l);
	s[y] -= 3;
}

int main() {
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		m[str] = i;
	}

	for (int i = 0; i < 6; i++) {
		string s1, s2;
		cin >> s1 >> s2 >> a[i].w >> a[i].d >> a[i].l;
		a[i].x = m[s1];
		a[i].y = m[s2];
	}

	go(0, 1.0);

	for (int i = 0; i < 4; i++) {
		printf("%.18lf\n", r[i]);
	}

	return 0;
}