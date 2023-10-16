#include <bits/stdc++.h>

using namespace std;

int arrows[1000000] = {0};

int main()
{
    int n, h, amount = 0;
    cin >> n;

    while(n--) {
        cin >> h;

        if (arrows[h+1] == 0) {
            amount++;
        } else {
            arrows[h+1]--;
        }

        arrows[h]++;
    }

    cout << amount << endl;
    return 0;
}