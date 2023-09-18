#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    cin >> n;
    
    int a, b, c;
    while (n, n--) {
        cin >> a >> b >> c;

        bool hasSolution = false;
        for(int x = -22; x <= 22 && !hasSolution; x++) {
            if (x * x <= c) {
                for(int y = -100; y <= 100 && !hasSolution; y++) {
                    if(y != x && x * x + y * y <= c) {
                        for(int z = -100; z <= 100 && !hasSolution; z++) {
                            if (z != x && z != y && x + y + z == a
									&& x * y * z == b
									&& x * x + y * y + z * z == c) {
								cout << x << " " << y << " " << z << "\n";
								hasSolution = true;
                                break;

							}
                        }
                    }
                }
            }
        }
        if(!hasSolution) cout << "No solution.\n";
    }
    return 0;
}
