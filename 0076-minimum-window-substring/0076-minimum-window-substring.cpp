#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t
        vector<int> targetCount(128, 0);
        for (char c : t) {
            targetCount[c]++;
        }

        int required = t.length();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        while (right < s.length()) {
            char rChar = s[right];
            if (targetCount[rChar] > 0) {
                required--;
            }
            targetCount[rChar]--;
            right++;

            // When all characters are matched, try to shrink the window from the left
            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    startIndex = left;
                }

                char lChar = s[left];
                targetCount[lChar]++;
                if (targetCount[lChar] > 0) {
                    required++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};