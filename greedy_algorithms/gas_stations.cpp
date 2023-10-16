#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> 


struct Pair {
    int first;
    int second;
};

bool customComparator(const Pair& pair1, const Pair& pair2) {
    if (pair1.first != pair2.first) {
        return pair1.first < pair2.first;
    } else {
        return pair1.second < pair2.second;
    }
}

int main() {
    int l, g;
    while (std::cin >> l >> g, l || g) {
        std::vector<Pair> xr(g);

        int point, range;
        for (int i = 0; i < g; i++) {
            std::cin >> point >> range;
            xr[i].first = std::max(point - range, 0);
            xr[i].second = std::min(point + range, l);
        }

        // Sorting the vector of pairs based on the custom comparison function
        std::sort(xr.begin(), xr.end(), customComparator);

        int position = 0;
        int i = 0;
        int aux = 0;
        int stations_needed = g;

        while (position < l) {
            aux = position;

            while(i < g && xr[i].first <= position) {
                aux = std::max(aux,xr[i].second);
                i++;
            }
            
            if(aux == position) break;
            
            position = aux;
            --stations_needed;
        }


        printf("%d\n",position < l? -1 : stations_needed);
    }

    return 0;
}
