#include <stdio.h>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

void sieveOfEratosthenes(int srt, int n)
{
    bool prime[n + 2];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = srt; p <= n; p++)
        if (prime[p])
            printf("%d\n", p);
}

int main() {
    int quantity;
    scanf("%d ", &quantity);

    for(int i = 0; i < quantity; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        sieveOfEratosthenes(a, b);

        if (i != quantity-1) {
            printf("\n");
        }
    }
    
    return 0;
}