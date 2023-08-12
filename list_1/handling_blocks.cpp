#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    std::vector<int> colorList(n);
    std::vector<std::vector<int>> groupLists(k);
    std::vector<int> finalList(n);

    for(int i = 0; i < n; i++) {
        int ni, ci;
        scanf("%d %d", &ni, &ci);

        colorList[i] = ci;
        groupLists[ci-1].push_back(ni);
    }

    for(int i = 0; i < k; i++) {
        std::sort(groupLists[i].begin(), groupLists[i].end());
    }

    for(int i = n - 1; i >= 0; i--) {
        finalList[i] = groupLists[colorList[i]-1].back();
        groupLists[colorList[i]-1].pop_back();
    }

    bool sorted = true;
    for (int i = 1; i < n; i++) {
        if (finalList[i - 1] > finalList[i]) {
            sorted = false;
            break;
        }
    }

    if(sorted) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}
