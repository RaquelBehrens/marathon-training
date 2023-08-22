#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i)
    {
        double c, d;
        cin >> c >> d;
        printf("Case %d: %.2f\n", i, c + 5.0 / 9.0 * d);
    }
}
