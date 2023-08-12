#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void simple_sieve(int limit, vector<int>& primes) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void segmented_sieve(int m, int n) {
    int limit = sqrt(n) + 1;
    vector<int> primes;
    simple_sieve(limit, primes);

    int range = n - m + 1;
    vector<bool> is_prime(range, true);

    for (size_t i = 0; i < primes.size(); ++i) {
        int p = primes[i];
        if (p * p > n) break;
        int start = max(p * p, (m + p - 1) / p * p);
        if (start == p) start += p;
        for (int j = start; j <= n; j += p) {
            is_prime[j - m] = false;
        }
    }

    if (m == 1) is_prime[0] = false;

    for (int i = 0; i < range; ++i) {
        if (is_prime[i]) {
            cout << i + m << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;
        segmented_sieve(m, n);

        if (t != 0) {
            cout << endl;
        }
    }

    return 0;
}