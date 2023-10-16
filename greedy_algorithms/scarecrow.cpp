#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int j = 1; j <= t; j++) {
        int n;
        cin >> n;

        vector<bool> spaces_covered(n+2);

        for(int i = 0; i < n; i++) {
            char c;
            cin >> c;
            spaces_covered[i] = c == '.' ? false : true;
        }

        int scarecrows = 0;
        for(int i = 0; i < n; i++) {
            if (!spaces_covered[i]) {
                scarecrows++;
                spaces_covered[i] = true;
                spaces_covered[i+1] = true;
                spaces_covered[i+2] = true;
            }
        }

        cout << "Case " << j << ": " << scarecrows << endl;
    }

    return 0;
}
