#include <iostream>
#include <stack> 
#include <map>
#include <set>
#include <iomanip>
#include <numeric> // for std::accumulate

using namespace std;

int main () {
    int k;
    cin >> k;

    for(int test = 1; test <= k; test++) {
        int n;
        cin >> n;
        map<int, set<int>> stamps;

        int maxStamp;

        for(int i = 1; i <= n; i++) {
            int m;
            cin >> m;

            int stamp;
            while(m, m--) {
                cin >> stamp;
                stamps[stamp].insert(i);

                if (stamp > maxStamp) maxStamp = stamp;
            }
        }

        int uniqueAmount[n] = {0};
        int arraySize = 0;
        for (map<int, set<int>>::iterator iter = stamps.begin(); iter != stamps.end(); iter++) {
            if ((iter->second).size() == 1) {
                uniqueAmount[(*((iter->second).begin())) - 1] += 1;
                arraySize += 1;
            }
        }

        cout << "Case " << test << ":";
        for (int unique = 0; unique < n; unique++) {
            cout << " ";
            double result = static_cast<double>(uniqueAmount[unique]) / arraySize;

            // Print the result with 6 decimal places and a percentage sign
            std::cout << std::fixed << std::setprecision(6) << result * 100 << "%";
        }
        
        cout << "\n";
    }

    return 0;
}