#include <iostream>
#include <stack> 
#include <map>
#include <set>

using namespace std;

int main () {
    int n;
    while(cin >> n, n) {
        std::multiset<int> tickets;
        long long total = 0;

        for(int i = 0; i < n; i++) {
            int ticketInLine;
            cin >> ticketInLine;

            while(ticketInLine, ticketInLine--) {
                int num;
                cin >> num;
                tickets.insert(num);
            }
            
            std::multiset<int>::iterator begin = tickets.begin();
            std::multiset<int>::iterator end = --tickets.end();

            total += *end - *begin;

            tickets.erase(end);
            tickets.erase(begin);
        }

        cout << total << '\n';
    }
    return 0;
}