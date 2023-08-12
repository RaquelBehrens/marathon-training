#include <stdio.h>

int main() {
    int t, d, m;
    scanf("%d %d %d", &t, &d, &m);

    int start = 0;
    for(int i = 0; i < m; i++) {
        int y;
        scanf("%d", &y);

        if(y - start >= t) {
            printf("Y\n");
            return 0;
        }
        start = y;
    }

    if(d - start >= t) {
        printf("Y\n");
        return 0;
    }

    printf("N\n");
    return 0;
}
