#include <stdio.h>

unsigned int reverse(unsigned int val) {
    unsigned int retval = 0;
    while(val > 0) {
        printf("%d\n", val%10);
        retval = 10*retval + val%10;
        val /= 10;
    }
    return retval;
}


int main() {
    int quantity;
    scanf("%d ", &quantity);

    for(int i = 0; i < quantity; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a = reverse(a);
        b = reverse(b);
        int c = reverse(a+b);
        printf("%d\n", c);
    }
    
    return 0;
}
