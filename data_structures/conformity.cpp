#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    string temp;

    while (1) {

        int n;
        cin >> n;
        int MAX = -1;
        if (n == 0) break;

        
        map<long long int, int> counter;
        for (int i = 0; i < n; i++) {
            
            int a[5];
            
            for (int j = 0; j < 5; j++) cin >> a[j];
            
            sort(a, a + 5);
            
            long long int temp = 0;

            for (int j = 0; j < 5; j++) 
                temp = temp * 1000 + a[j];

            if (counter.find(temp) == counter.end()) 
                counter[temp] = 1;
            else counter[temp]++;

            MAX = max(counter[temp], MAX);
        }
        
        int ans = 0;
        
        for (map<long long int, int>::iterator iter = counter.begin(); iter != counter.end(); iter++) 
            if (iter->second == MAX) 
                ans += iter->second;
        
        cout << ans << endl;
        }


    return 0;
}