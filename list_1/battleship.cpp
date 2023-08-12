#include <stdio.h>

int main() {
    const int gridSize = 10;
    int quantity;
    scanf("%d", &quantity);

    int grid[gridSize][gridSize] = {};

    for(int i = 0; i < quantity; i++) {
        int d, l, r, c;
        scanf("%d %d %d %d", &d, &l, &r, &c);

        r -= 1;
        c -= 1;

        int shipSizeLimit = (d == 0) ? c + l - 1 : r + l - 1;
        if (shipSizeLimit >= gridSize) {
            printf("N\n");
            return 0;
        }

        for (int j = (d == 0) ? c : r; j <= shipSizeLimit; ++j) {
            if (d == 0) {
                if (grid[r][j] == 1) {
                    printf("N\n");
                    return 0;
                }
                grid[r][j] = 1;
            } else {
                if (grid[j][c] == 1) {
                    printf("N\n");
                    return 0;
                }
                grid[j][c] = 1;
            }
        }
    }

    printf("Y\n");
    return 0;
}
