#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate all subsets of a list of integers along with their sums (without repeating values)
void generateSubsetsWithSums(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& allSubsets, vector<int>& subsetSums) {
    if (index == nums.size()) {
        allSubsets.push_back(currentSubset); // Add the current subset to the result
        int sum = 0;
        for (int num : currentSubset) {
            sum += num;
        }
        subsetSums.push_back(sum); // Add the sum of the current subset
        return;
    }

    // Exclude the current element
    generateSubsetsWithSums(nums, index + 1, currentSubset, allSubsets, subsetSums);

    // Include the current element if it's not already in the currentSubset
    if (find(currentSubset.begin(), currentSubset.end(), nums[index]) == currentSubset.end()) {
        currentSubset.push_back(nums[index]);
        generateSubsetsWithSums(nums, index + 1, currentSubset, allSubsets, subsetSums);
        currentSubset.pop_back();
    }
}

int main()
{
    int n, amount;
    vector<int> tracks;

    vector<vector<int>> allSubsets;
    vector<int> subsetSums;

    vector<int> currentSubset;

    while(cin >> n >> amount && (n || amount)) {
        int num;
        tracks.clear();
        
        for(int i = 0; i < amount; i++) {
            cin >> num;
            tracks.push_back(num);
        }

        allSubsets.clear();
        subsetSums.clear();
        currentSubset.clear();

        generateSubsetsWithSums(tracks, 0, currentSubset, allSubsets, subsetSums);

        int difference = n;
        int index = amount+1;
        for(int i = 0; i < subsetSums.size(); i++) {
            if (0 <= n - subsetSums.at(i) && n - subsetSums.at(i) <= difference) { 
                difference = n - subsetSums.at(i);
                index = i;
            };
        }

        for(int i = 0; i < allSubsets[index].size(); i++){
            cout << allSubsets[index][i] << " ";
        }
        cout << "sum:" << subsetSums[index] << '\n';

    }
    return 0;
}
