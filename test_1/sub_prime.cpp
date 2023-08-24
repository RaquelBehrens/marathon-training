#include <iostream>

using namespace std;

int main()
{
    int b, n;
    int r[20];

    scanf("%d %d", &b, &n);

    while(b) {
        for(int i = 0; i < b; i++) {
            int reserve;
            scanf("%d", &r[i]);
        }

        for(int i = 0; i < n; i++) {
            int d, c, v;
            scanf("%d %d %d", &d, &c, &v);
            r[d-1] -= v;
            r[c-1] += v;
        }

        bool isPossible = true;
        for(int i = 0; i < b; i++) {
            if(r[i] < 0) {
                isPossible = false;
            }
        }
        
        if (isPossible) { printf("S\n"); } else { printf("N\n"); };

        scanf("%d %d", &b, &n);
    }
}