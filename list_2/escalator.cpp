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

        if(d == 0) {
            if (last_left != -1) {
                if (arrive[last_left] + 10 >= a) {
                    arrive[i] = arrive[last_left+1];
                    direction[i] = direction[last_left+1];
                    arrive[last_left+1] = a;
                    direction[last_left+1] = d;
                }
            }
            last_left = i;
        } else {
            if (last_right != -1) {
                if (arrive[last_right] + 10 >= a) {
                    arrive[i] = arrive[last_right+1];
                    direction[i] = direction[last_right+1];
                    arrive[last_right+1] = a;
                    direction[last_right+1] = d;
                }
            }

            last_right = i;
        }
    }

    int time = 0;

    int first_direction = direction[0];
    int current_direction = first_direction;
    int x = 0;
    while(x < n -1) {
        while (current_direction == first_direction && x < n -1) {
            x++;
            current_direction = direction[x];
        }

        time += arrive[x] + 10;

        if(x < n) {
            first_direction = direction[x];
        }
    }

    cout << time << '\n';
    
    return 0;
}
