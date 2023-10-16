#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int arrive[n];
    int direction[n];

    int last_right = -1;
    int last_left = -1;

    int a, d;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &d);
        arrive[i] = a;
        direction[i] = d;
    }

    int time[n] = {};

    for (int i = 0; i < n; i++) {
        int now = arrive[i];
        if (i != 0) {
            if (direction[i-1] != direction[i]) {
                if (time[i-1] > arrive[i]) {
                    time[i] = time[i-1]+10;
                } else {
                    time[i] = arrive[i] + 10;
                }
            } else {
                if (time[i-1] > arrive[i]+10) {
                    time[i] = time[i-1];
                } else {
                    time[i] = arrive[i] + 10;
                }
            }
        } else {
            time[i] = arrive[i]+10;
        }
        if (i+2 < n) {
            if (direction[i] != direction[i+1]) {
                int look_forward = i+2;
                while (look_forward < n) {
                    if (direction[i] == direction[look_forward]) {
                        
                        if (time[i] > arrive[look_forward]) {
                            int a, d, t;
                            a = arrive[i+1];
                            d = direction[i+1];
                            t = time[i+1];
                            arrive[i+1] = arrive[look_forward];
                            direction[i+1] = direction[look_forward];
                            time[i+1] = time[look_forward];
                            arrive[look_forward] = a;
                            direction[look_forward] = d;
                            time[look_forward] = t;
                        }
                        break;
                    }
                    look_forward++;
                }
            }
        }
    }

    cout << time[n-1] << '\n';
    
    return 0;
}
