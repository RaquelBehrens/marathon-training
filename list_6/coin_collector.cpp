#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> values;
        for (int i = 0; i < n; ++i)
        {
            int value;
            cin >> value;
            values.push_back(value);
        }

        int sum = 1;
        int coins = values.size() > 1? 2 : 1;
        
        for (int i = 1; i < values.size() - 1; ++i)
            if (sum + values[i] < values[i + 1])
            {
                sum += values[i];
                ++coins;
            }

        cout << coins << endl;
    }

    return 0;
}
