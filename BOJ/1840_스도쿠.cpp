#include<iostream>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define set(i,j,k,l) used[0][i][k]=used[1][j][k]=used[2][3*((i-1)/3)+1+(j-1)/3][k]=l

using namespace std;

int t[82][3], s[10][10] = { 0, }, used[3][10][10] = { 0, };

bool valid(int i, int j, int k) {
	return !(used[0][i][k] || used[1][j][k] || used[2][3 * ((i - 1) / 3) + 1 + (j - 1) / 3][k]);
}

bool fill(int i, int j) {
	if (i == 9 && j == 10) return true;
	if (j == 10)return fill(i + 1, 1);
	if (s[i][j] != 0)return fill(i, j + 1);

	int ret = false;
	f(k, 1, 9)if (valid(i, j, k)) {
		set(i, j, k, 1);
		ret = fill(i, j + 1);
		set(i, j, k, 0);
		if (ret)break;
	}
	return ret;
}

int main() {
	f(i, 1, 81)cin >> t[i][0] >> t[i][1] >> t[i][2];
	int a, b, c, j = 0;
	f(i, 1, 81) {
		a = t[i][0], b = t[i][1], c = t[i][2];
		if (!valid(a, b, c)) {
			j = i;
			while (!fill(1, 1)) {
				--j;
				a = t[j][0], b = t[j][1], c = t[j][2];
				s[a][b] = 0;
				set(a, b, c, 0);
			}
			break;
		}
		s[a][b] = c;
		set(a, b, c, 1);
	}
	cout << (j == 0 ? -1 : j);
	return 0;
}