#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, r;
    while (cin >> n >> d >> r, n || d || r) {
        vector<int> morning_routes(n);
        for(int i = 0; i < n; i++) {
            cin >> morning_routes[i];
        }
        std::sort(morning_routes.begin(), morning_routes.end());

        vector<int> evening_routes(n);
        for(int i = 0; i < n; i++) {
            cin >> evening_routes[i];
        }
        std::sort(evening_routes.begin(), evening_routes.end(), std::greater<int>());

        int hours = 0;
        int payment = 0;
        for (int i = 0; i < n; i++) {
			hours = morning_routes[i] + evening_routes[i];
			if (hours > d)
				payment += (hours - d) * r;
		}

        cout << payment << endl;

    }

    return 0;
}
