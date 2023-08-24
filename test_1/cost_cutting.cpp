#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        int survivor;

        if ((a <= b && a >= c) || (a >= b && a <= c))
            survivor = a;
        else if ((b <= a && b >= c) || (b >= a && b <= c))
            survivor = b;
        else
            survivor = c;

        printf("Case %d: %d\n", i, survivor);
    }
    return 0;
}