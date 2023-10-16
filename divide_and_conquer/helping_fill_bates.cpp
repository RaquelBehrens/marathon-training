#include <bits/stdc++.h>

using namespace std;

int findSmallestGreater(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();
    int smallestGreater = -1; // Initialize with a value that indicates not found

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target) {
            // Update the smallestGreater and search the left half for potentially smaller values
            smallestGreater = arr[mid];
            right = mid;
        } else {
            // Search the right half
            left = mid + 1;
        }
    }

    return smallestGreater;
}


int main()
{
    string S;
    vector<int> v[123];

    getline(cin, S);
    int position = 0;
    for(string::iterator i = S.begin(); i != S.end(); ++i) {
        v[int(*i - '0')].push_back(position);
        position++;
    }

    int Q;
    cin >> Q;
    cin.ignore();
    string SS;

    while (Q--) {
        getline(cin, S);
        int first_position = 0;
        position = -1;

        bool found = true;
        
        int iterator = 0;
        for(string::iterator i = S.begin(); i != S.end(); ++i) {
            position = findSmallestGreater(v[int(*i - '0')], position);

            if (position < 0) {
                found = false;
                break;
            }

            if (iterator == 0) {
                first_position = position;
            }
            iterator++;
        }

        if (found) {
            cout << "Matched " << first_position << " " << position << '\n';
        } else {
            cout << "Not matched\n";
        }

    }
    return 0;
}
