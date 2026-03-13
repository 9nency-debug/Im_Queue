#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestWPI(vector<int>& hours) {
    unordered_map<int, int> firstIndex;
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < hours.size(); i++) {
        
        // Convert into +1 and -1
        if (hours[i] > 8)
            prefixSum += 1;
        else
            prefixSum -= 1;

        // Case 1: entire subarray from saf0 to i is valid
        if (prefixSum > 0) {
            maxLength = i + 1;
        }
        else {
            // If prefixSum - 1 exists
            if (firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                maxLength = max(maxLength, i - firstIndex[prefixSum - 1]);
            }
        }

        // Store first occurrence of prefixSum
        if (firstIndex.find(prefixSum) == firstIndex.end()) {
            firstIndex[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> hours = {9, 9, 6, 0, 6, 6, 9};
    cout << longestWPI(hours);
    return 0;
}
