#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v, tc = 0;
    while(cin >> n, n) {
        if(tc++) cout << endl;
        
        vector<int> bags;
        for(int i = 0; i < n; i++){
            cin >> v;
            bags.push_back(v);
        }
        sort(bags.begin(),bags.end());
        
        int numBags = 1;
        int currentBag = 1;

        for(int i = 1; i < bags.size(); i++){
            if(bags[i] == bags[i-1]) {
                currentBag++;
            } else {
                currentBag = 1;
            }
            numBags = max(currentBag, numBags);
        }

        cout << numBags << '\n';
        
        for(int i = 0; i < numBags; i++){
            cout << bags[i];
            for(int j = i+numBags; j < n; j += numBags)
                cout << ' ' << bags[j];
            cout << '\n';
        }
    }
}