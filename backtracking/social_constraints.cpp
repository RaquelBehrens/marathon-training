#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findElementIndex(const std::vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == target) {
            return i; // Return the index as an integer
        }
    }
    return -1; // Return -1 if the element is not found
}

int main()
{
    int n, m;

    while (cin >> n >> m, n || m) {
        std::vector<int> seats;
        int constraints[20][3];

        for (int i = 0; i < n; i++) {
            seats.push_back(i);
        }

        for (int i = 0; i < m; i++) {
            cin >> constraints[i][0] >> constraints[i][1] >> constraints[i][2];
        }

        int combinations = 0;
        do {
            bool hasConflict = false;

            for (int i = 0; i < m; i++) {
                int posA = findElementIndex(seats, constraints[i][0]);
                int posB = findElementIndex(seats, constraints[i][1]);

                if(constraints[i][2] > 0) {
                    if(abs(posA-posB) > constraints[i][2]) {
                        hasConflict = true;
                        break;
                    }
                } else {
                    if(abs(posA-posB) < (-constraints[i][2])) {
                        hasConflict = true;
                        break;
                    }
                }
            }

            if (!hasConflict) combinations++;
        } while (next_permutation(seats.begin(), seats.end()));

        cout << combinations << '\n';
    }

    return 0;
}
