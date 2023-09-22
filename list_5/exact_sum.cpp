#include <bits/stdc++.h>

using namespace std;

int findClosestValue(const int arr[], int size, int target, int startIndex) {
    int left = startIndex;
    int right = size - 1;
    int closest = -1; // Initialize with -1 to indicate no match found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            closest = arr[mid];
            left = mid + 1; // Move to the right half to find a smaller value or a closer match
        } else {
            right = mid - 1; // Move to the left half
        }
    }

    return closest;
}

int binarySearch(const int arr[], int size, int targetValue, int startIndex) {
    int left = startIndex;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == targetValue) {
            return arr[mid]; // Found the target value
        } else if (arr[mid] < targetValue) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    return -1; // Not found
}


int main()
{
    int n, max, a, b;

     while (cin >> n)
    {
        int books[n];

        for(int i = 0; i < n; i++) {
            cin >> books[i];
        }

        std::sort(books, books + n);

        cin >> max;
        
        int difference = max;
        int valueFound;
        for(int i = 0; i < n; i++) {
            valueFound = binarySearch(books, n, max-books[i],i+1);

            if (valueFound >= 0 && abs(books[i]-valueFound) < difference) {
                a = books[i];
                b = valueFound;
                difference = abs(a-b);
            }
        }

        cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
    }
    
    return 0;
}
