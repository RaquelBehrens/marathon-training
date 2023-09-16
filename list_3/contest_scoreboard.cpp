#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

bool isBlank(const std::string& str) {
    for (char c : str) {
        if (!std::isspace(c)) {
            return false; // Found a non-whitespace character
        }
    }
    return true; // All characters are whitespace
}

typedef int IntPair[2];

int main () {
    int n;
    cin >> n;

    std::cin.ignore();

    std::string input;
    getline(std::cin, input);

    while(n, n--) {  

        int people[100][3] = {0};   
        int entered = false;

        while (true) {
            getline(std::cin, input);
            if (isBlank(input)) {
                break;
            }     

            entered = true;       

            int person, problem, minutes;
            char result;

            istringstream iss(input);
            iss >> person >> problem >> minutes >> result;

            if (result == 'I') {
                people[person-1][0] += 20;
            } else if (result == 'C') {
                people[person-1][0] += minutes;
                people[person-1][1] += 1;
            }

            people[person-1][2] = 1;
        }  


        if (entered) {
            
            int sorted_people[100];
            for(int i = 0; i < 100; i++) {
                sorted_people[i]= i;
            }

            const int listSize = sizeof(people) / sizeof(people[0]);

            std::sort(sorted_people, sorted_people + listSize, [&people](int a, int b) {
                return people[a][1] > people[b][1]; // Sort in descending order based on the second element
            });

            // Create a vector of vectors to group elements by the matrix's third element
            std::vector<std::vector<int>> groupedElements;

            // Iterate through the sorted list and group elements
            for (int i = 0; i < listSize; ++i) {
                int matrixElement = sorted_people[i];
                int secondElement = people[matrixElement][1];

                bool foundGroup = false;
                // Iterate through existing groups to find the matching one
                for (auto& group : groupedElements) {
                    if (!group.empty() && people[group[0]][1] == secondElement) {
                        group.push_back(matrixElement);
                        foundGroup = true;
                        break;
                    }
                }

                // If no matching group was found, create a new group
                if (!foundGroup) {
                    groupedElements.push_back({matrixElement});
                }
            }

            // Sort elements within each group based on the matrix's second element (the second column)
            for (auto& group : groupedElements) {
                std::sort(group.begin(), group.end(), [&people](int a, int b) {
                    return people[a][0] < people[b][0]; // Sort in ascending order based on the first element
                });
            }

            // Create a map to further group elements inside groupedElements by the matrix's second element
            std::vector<std::vector<std::vector<int>>> groupedByFirstElement;

            // Iterate through the groupedElements and further group elements by the matrix's second element
            int iteration = 0;
            for (auto& group : groupedElements) {
                const int listSize = group.size(); 
                std::vector<std::vector<int>> preOrderedByFirst;

                // Iterate through the sorted list and group elements
                for (int i = 0; i < listSize; ++i) {
                    int checkElement = people[group[i]][0];
                    bool foundGroup = false;

                    // Iterate through existing groups to find the matching one
                    for (auto& secondGroup : preOrderedByFirst) {
                        if (!secondGroup.empty() && people[secondGroup[0]][1] == checkElement) {
                            secondGroup.push_back(group[i]);
                            foundGroup = true;
                            break;
                        }
                    }

                    // If no matching group was found, create a new group
                    if (!foundGroup) {
                        preOrderedByFirst.push_back({group[i]});
                    }
                }


                groupedByFirstElement.push_back(preOrderedByFirst);
                iteration++;
            }

            
            // Sort each element within each group inside groupedByFirstElement
            for (auto& firstElementGroup : groupedByFirstElement) {
                for (auto& group : firstElementGroup) {
                    std::sort(group.begin(), group.end());
                }
            }


            // Print the matrix in the order provided by secondElementGroup
            for (const auto& firstElementGroup : groupedByFirstElement) {
                for (const auto& group : firstElementGroup) {
                    for (const auto& element : group) {
                        // Print the elements from the original matrix based on the stored indices
                        if (people[element][2] > 0) {
                            std::cout << element+1 << ' ' << people[element][1] << ' ' << people[element][0] << "\n";
                        }
                    }
                }
            }
        }     

        cout << '\n';
        
   }
    return 0;
}