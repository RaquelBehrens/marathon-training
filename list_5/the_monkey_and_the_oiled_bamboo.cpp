#include <bits/stdc++.h>

using namespace std;

int n;

bool canJump(const vector<int> &rungs, int height) {
    int lastHeight = 0;
    for (int i = 0; i < n; i++) {
        int dif = rungs[i] - lastHeight;
        if (dif == height) {
            height--;
        }
        else if (dif > height) {
            return false;
        }
        lastHeight = rungs[i];
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        cin >> n;
        vector<int> rungs(n);
        for(int i = 0; i < n; i++) {
            cin >> rungs[i];
        }

        int l = 1;
        int r = 10000000;
        int height = 0;

        while (l <= r) {
            int mid = (l+r)/2;
            if (canJump(rungs, mid)) {
                height = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "Case " << j << ": " << height << '\n';      
    }

    return 0;
}
