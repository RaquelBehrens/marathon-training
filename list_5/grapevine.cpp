#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int property[500][500] = {0};

    while (cin >> n, cin >> m, n and m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> property[i][j];
            }
        }
        
        int q;
        cin >> q;

        int l, u;
        while(q--) {
            cin >> l >> u;

            int maxSize = 0;
            for(int i = 0; i < n; i++) {
                int minPosition = lower_bound(property[i], property[i] + m, l) - property[i];
                for(int j = 0; j < m; j++) {
                    if(n <= i + j or m <= minPosition + j or u < property[i + j][minPosition + j])
						break;
					
					maxSize = max(maxSize, j + 1);
                }
            }
            cout << maxSize << "\n";
        }
        cout << "-\n";        
    }

    return 0;
}
