#include <bits/stdc++.h>

using namespace std;

int n;
int edges[105][105];
int dominateds[105][105];

int used[105];

void dfs(int nd, int st) {
    if(nd == st) {
		return;
	}
	used[nd] = 1;
    for(int m = 0; m < n; m++) {
        if(edges[nd][m] && !used[m]) {
            dfs(m, st);
        }
    }
}


int main() {
    int t, e;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> e;
				edges[j][k] = e;
			}
		}

		int reachables_from_zero[105] = {};
        for(int j = 0; j < n; j++)
            used[j] = 0;
        dfs(0, -1);
        for(int j = 0; j < n; j++)
            reachables_from_zero[j] = used[j];

		
		for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++)
                used[k] = 0;
            dfs(0, j);
            for(int k = 0; k < n; k++)
                if(reachables_from_zero[k] && !used[k])
                    dominateds[j][k] = 1;
                else
                    dominateds[j][k] = 0;
            dominateds[j][j] = reachables_from_zero[j];

        }

        cout << "Case " << i << ":" << endl;
        cout << '+';
        for(int j = -n+1; j < n; j++)
            cout << '-';
        cout << "+" << endl;
		
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << '|';
                putchar(dominateds[j][k] ? 'Y' : 'N');
            }
            cout << '|' << endl;

            cout << '+';
			for(int k = -n+1; k < n; k++)
				cout << '-';
			cout << "+" << endl;
        }
	}
	return 0;
}