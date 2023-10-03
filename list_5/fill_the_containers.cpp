#include <bits/stdc++.h>

using namespace std;

int n, m;

bool fillContainers(const vector<int> &vessels, int capacity) {
    int container = 1;
    int c = capacity;
    for (int i = 0; i < vessels.size(); ++i)
    {
        // No container can contain so much milk.
        if (vessels[i] > capacity)
            return false;

        if (vessels[i] > c)
        {
            // Already m containers are filled.
            if (container == m)
                return false;
            ++container;
            c = capacity;
        }
        c -= vessels[i];
    }
    return true;
}

int main()
{
    while (cin >> n >> m) {
        vector<int> vessels(n);
        for(int i = 0; i < n; i++) {
            cin >> vessels[i];
        }

        int l = 1;
        int r = 1000000000;
        int capacity = 0;

        while (l <= r) {
            int mid = (l+r)/2;
            if (fillContainers(vessels, mid)) {
                capacity = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << capacity << '\n';      
    }

    return 0;
}
