#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;


char florida_map[105][105];
int used[105][105];
int area = 0;

void dfs(int nd, int st) {
    if(nd < 0 || st < 0 || florida_map[nd][st] == 0)
        return;
    if(used[nd][st] != 0 || florida_map[nd][st] != 'W')
        return;

    used[nd][st] = 1;
    area++;

    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            dfs(nd+i, st+j);
}


int main() {
    int t, e, i, j, k;
	cin >> t;
    
    char str[105];
	while (t--) {
        memset(florida_map, 0, sizeof(florida_map));
        int n = 0;
        while(scanf("%s", str)) {
            if(str[0] == '\0')
                break;
            else if ((str[0] != 'W' && str[0] != 'L')) {
                i = str[0] - '0';
                cin >> j;
                memset(used, 0, sizeof(used));
                area = 0;
                dfs(i-1, j-1);
                printf("%d\n", area);
            } else {
                strncpy(florida_map[n], str, 105);
                n++;
            }
        }

        if(t)
            cout << "" << endl;
	}
	return 0;
}
