#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <string.h>

using namespace std;

int main () {
    string word;

    while (cin >> word, word != "#") {
        if (next_permutation(word.begin(), word.end())) {
            cout << word << '\n';
        } else {
            cout << "No Successor\n";
        }
    }

  return 0;
}