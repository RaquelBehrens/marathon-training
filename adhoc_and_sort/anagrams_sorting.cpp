#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string removeWhitespaces(const string& input) {
    string result;
    for (char c : input) {
        if (!isspace(c)) {
            result += c;
        }
    }
    return result;
}

bool isEqual(const string& first, const string& second) {
    int first_size = first.size() - 1;
    if (first_size != second.size() - 1) {
        return false;
    }

    for (int i = 0; i < first_size; ++i)
        if (first[i] != second[i])
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string word;

    string separator = "";    
    for(int j = 0; j < n; j++) {
        string sorted_anagrams[100];
        string anagrams[100];
        int i;

        for(i = 0; i < 100; i++) {
            string word;
            getline(cin, word);
            anagrams[i] = word;
            
            if (word.empty()) {
                break;
            }

            string word_without_spaces = removeWhitespaces(word);

            sort(word_without_spaces.begin(), word_without_spaces.end());
            sorted_anagrams[i] = word_without_spaces;
        }

        cout << separator;
        separator = "\n";

        bool found_anagrams;
        for (int k = 0; k < i; k++) {
            for (int l = k+1; l < i; l++) {
                if (isEqual(sorted_anagrams[k], sorted_anagrams[l])) {
                    cout << anagrams[k] << " = " << anagrams[l] << '\n';
                    found_anagrams = true;
                }
            }
        }

        if (!found_anagrams) {
            cout << 0 << '\n';
        }
    }

    return 0;
}
