#include <iostream>

int match(char first_move, char second_move) {
    if (first_move == second_move) {
        return 0;
    }
    if (first_move == 's') {
        if (second_move == 'p') {
            return 1;
        } else {
            return -1;
        }
    }
    if (first_move == 'p') {
        if (second_move == 's') {
            return -1;
        } else {
            return 1;
        }
    }
    if (first_move == 'r') {
        if (second_move == 's') {
            return 1;
        } else {
            return -1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    bool isFirst = true;

    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
            break;
            
        scanf("%d", &k);

        int games = (k*n*(n-1))/2;
        int p1, p2;
        char m1[10], m2[10];

        int playersWins[101] = {};
        int playersLosses[101] = {};
        
        for (int i = 0; i < games; i++) {
            scanf("%d %s %d %s", &p1, m1, &p2, m2);
            int result = match(m1[0], m2[0]);

            if (result == 1) {
                playersWins[p1]++;
                playersLosses[p2]++;
            } else if (result == -1) {
                playersWins[p2]++;
                playersLosses[p1]++;
            }
        }

        if (!isFirst)
            printf("\n");
            
        isFirst = false;

        for (int i = 1; i <= n; ++i) {
            if (playersLosses[i] + playersWins[i] == 0)
                printf("-\n");
            else
                printf("%.3f\n", (1.0 * playersWins[i]) / (playersLosses[i] + playersWins[i]));
        }
    }
}
