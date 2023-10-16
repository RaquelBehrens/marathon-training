#include <iostream>
#include <algorithm>

using namespace std;
#define MORE_THAN_ONE 21

const vector<int> letterBase(128, 0);

vector<int> GetLetterCounts(string word)
{
    vector<int> letterCounts(letterBase);
    
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        if (*iter != ' ')
            ++letterCounts[*iter];
    }
    
    return letterCounts;
}

bool isEqual(const vector<int>& first, const vector<int>& second)
{
    for (int i = 0; i < 128; ++i)
        if (first[i] != second[i])
            return false;
    return true;
}

int main() {
    int l, c;
    scanf("%d %d", &l, &c);

    char grid[l][c];
    char element;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            cin >> element;
            grid[i][j] = element;
        }
    }

    int n;
    scanf("%d", &n);

    string anagram;
    vector<int> anagram_letterCounts;

    char special_grid[l][c];
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            special_grid[i][j] = 0;
        }
    }
    cin.ignore();

    for(int i = 1; i <= n; i++) {
        getline(cin, anagram);
        anagram_letterCounts = GetLetterCounts(anagram);

        int size_anagram = anagram.size();

        //checking lines
        for(int j = 0; j < l; j++) {
            for(int k = 0; k <= c - size_anagram; k++) {
                // Create a string from a range of characters in the array
                char* startPtr = grid[j] + k; // Start at index 1
                char* endPtr = grid[j] + k + size_anagram;   // End at index 4 

                std::string strFromRange(startPtr, endPtr);
                
                vector<int> test_letterCounts = GetLetterCounts(strFromRange);

                if (isEqual(anagram_letterCounts, test_letterCounts)) {
                    for (int m = k; m < k+size_anagram; m++) {
                        if (special_grid[j][m] == 0) {
                            special_grid[j][m] = i;
                        } else {
                            if (special_grid[j][m] != i) {
                                special_grid[j][m] = MORE_THAN_ONE;
                            }
                        }
                        
                    }
                }

            }
        }

        //checking columns
        for(int j = 0; j < c; j++) {
            for(int k = 0; k <= l - size_anagram; k++) {
                std::string strFromRange;
                for (int m = k; m < k + size_anagram; m++) {
                    strFromRange += grid[m][j];
                }
                
                vector<int> test_letterCounts = GetLetterCounts(strFromRange);

                if (isEqual(anagram_letterCounts, test_letterCounts)) {
                    for (int m = k; m < k+size_anagram; m++) {
                        if (special_grid[m][j] == 0) {
                            special_grid[m][j] = i;
                        } else {
                            if (special_grid[m][j] != i) {
                                special_grid[m][j] = MORE_THAN_ONE;
                            }
                        }
                        
                    }
                }

            }
        }

        // Checking first diagonal (top-left to bottom-right)
        for(int j = 0; j <= l - size_anagram; j++) {
            for(int k = 0; k <= c - size_anagram; k++) {
                std::string strFromRange;
                for (int m = 0; m < size_anagram; m++) {
                    strFromRange += grid[j + m][k + m];
                }
                
                vector<int> test_letterCounts = GetLetterCounts(strFromRange);

                if (isEqual(anagram_letterCounts, test_letterCounts)) {
                    for (int m = 0; m < size_anagram; m++) {
                        if (special_grid[j + m][k + m] == 0) {
                            special_grid[j + m][k + m] = i;
                        } else {
                            if (special_grid[j + m][k + m] != i) {
                                special_grid[j + m][k + m] = MORE_THAN_ONE;
                            }
                        }
                    }
                }
            }
        }

        // Checking second diagonal (top-right to bottom-left)
        for(int j = 0; j <= l - size_anagram; j++) {
            for(int k = size_anagram - 1; k < c; k++) {
                std::string strFromRange;
                for (int m = 0; m < size_anagram; m++) {
                    strFromRange += grid[j + m][k - m];
                }
                
                vector<int> test_letterCounts = GetLetterCounts(strFromRange);

                if (isEqual(anagram_letterCounts, test_letterCounts)) {
                    for (int m = 0; m < size_anagram; m++) {
                        if (special_grid[j + m][k - m] == 0) {
                            special_grid[j + m][k - m] = i;
                        } else {
                            if (special_grid[j + m][k - m] != i) {
                                special_grid[j + m][k - m] = MORE_THAN_ONE;
                            }
                        }
                    }
                }
            }
        }


    }

    int special = 0;

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if (special_grid[i][j] == 21) {
                special++;
            }
        }
    }

    cout << special << '\n';

    return 0;
}
