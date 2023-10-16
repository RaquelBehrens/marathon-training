#include <iostream>
#include <stack> 
#include <map>
#include <set>

using namespace std;

int main () {
    int n;
    int iterations = 1;

    while(cin >> n, n) {
        int setOfIntegers[n];
        set<int> sums;

        for(int i = 0; i < n; i++) {
            cin >> setOfIntegers[i];

            for (int j = 0; j < i; ++j)
                if (setOfIntegers[j] != setOfIntegers[i])
                    sums.insert(setOfIntegers[j] + setOfIntegers[i]);
        }

        int m;
        cin >> m;

        cout << "Case " << iterations++ << ":\n";

        for(int i = 0; i < m; i++) {
            int num, best;
            cin >> num;

            set<int>::iterator iter = sums.lower_bound(num);
            if (iter == sums.begin())
                best = *iter;
            else if (iter == sums.end()) {
                --iter;
                best = *iter;
            } else {
                best = *iter;
                --iter;
                if (abs(best - num) > abs(*iter - num))
                    best = *iter;
            }
            
            cout << "Closest sum to " << num << " is " << best << ".\n";
        }
    }
    return 0;
}