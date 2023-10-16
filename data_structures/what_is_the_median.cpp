#include <iostream>     // std::cout
#include <algorithm>    // std::nth_element
#include <vector>       // std::vector
#include <cmath>

using namespace std;

int main () {
    std::vector<int> n;
    int x;
    int result;

    while (scanf("%d ", &x) != EOF) {
        n.push_back(x);
        result = 0;

        int index = 0;
        index = (n.size() / 2);
            nth_element(n.begin(), n.begin()+index, n.end());
            result += n[index];
        
        if(n.size() % 2 == 0) {
            index = (n.size() / 2)-1;
            nth_element(n.begin(), n.begin()+index, n.end());
            result += n[index];
            result = result/2;
        }

        cout << result << '\n';
        
    }

  return 0;
}