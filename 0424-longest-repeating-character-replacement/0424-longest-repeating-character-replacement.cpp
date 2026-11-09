#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int left = 0, max_freq = 0, max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'A']++;
            max_freq = std::max(max_freq, count[s[right] - 'A']);

            // If the number of characters to replace exceeds k, shrink the window from the left
            if ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};