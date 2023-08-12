#include <stdio.h>

int main() {
    int money = 100;
    int max = 100;

    int quantity;
    scanf("%d", &quantity);

    for(int i = 0; i < quantity; i++) {
        int box;
        scanf("%d", &box);

        money = money + box;

        if (max < money) {
            max = money;
        }
    }

    printf("%d\n", max);
    
    return 0;
}
