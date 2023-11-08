#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n;
vector<int> touches[maxn];
int used[maxn] = {};

int order[maxn] = {};
int r = 0;
int isImpossible = false;

void dfs(int x) {
    if(isImpossible) {
		return;
	}
    used[x] = 1;

    for (int i = 0; i < touches[x].size(); i++) {
		int v = touches[x][i];
		if (used[v] == 0) dfs(v);
		else if (used[v] == 1) {
			isImpossible = true;
			return;
		}
	}
	order[r] = x;
    r++;
	used[x] = 2;
}

int main() {
    int m, a, b;

	while (cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++)
			used[i] = 0, order[i] = 0, touches[i].clear();

        r = 0;
        isImpossible = false;

		for (int j = 0; j < m; j++) {
            cin >> a >> b;
			touches[a-1].push_back(b-1);
		}

		for (int i = 0; i < n && !isImpossible; i++)
			if (used[i] == 0) dfs(i);

        if (isImpossible) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            while (r--) {
                cout << order[r]+1 << endl;
            }
        }
	}
	return 0;
}