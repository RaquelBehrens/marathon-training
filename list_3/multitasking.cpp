#include <iostream>
#include <stack> 
#include <bitset> 

using namespace std;

const int maxMinutes = 1000000;

int main () {
    bitset<maxMinutes+1> minutes;

    int n, m;
    while (cin >> n >> m, n + m) {
        int start, end, repetition;
        bool valid = true;

        for(int i = 0; i < n; i++) {
            cin >> start >> end;
            for (int j = start; valid && j < end; j++) {
                valid = !minutes[j];
                minutes[j] = 1;
            }
        }

        if (valid) {
            for(int i = 0; i < m; i++) {
                cin >> start >> end >> repetition;
                    while (valid && start < maxMinutes) {
                    for (int spot = start; valid && spot < end; ++spot) {
                        valid = !minutes[spot];
                        minutes[spot] = true;
                    }
                    
                    start += repetition;
                    end = min(end + repetition, maxMinutes);
                }
            }
        }

        cout << (valid ? "NO CONFLICT\n" : "CONFLICT\n");
    }
    return 0;
}