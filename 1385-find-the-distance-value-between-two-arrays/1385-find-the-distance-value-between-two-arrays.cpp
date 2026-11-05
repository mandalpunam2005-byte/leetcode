#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int distanceValue = 0;
        
        for (int x : arr1) {
            // Find the first element in arr2 that is strictly greater than (x + d)
            auto it = std::upper_bound(arr2.begin(), arr2.end(), x + d);
            
            // Check if the predecessor exists and if its absolute difference with x is <= d
            bool found = false;
            if (it != arr2.begin()) {
                auto prev_it = std::prev(it);
                if (std::abs(*prev_it - x) <= d) {
                    found = true;
                }
            }
            
            // If no such element in arr2 is within distance d, count it
            if (!found) {
                distanceValue++;
            }
        }
        
        return distanceValue;
    }
};