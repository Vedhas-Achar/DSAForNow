class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        // Store the frequency of each character in t
        for (char c : t)
            need[c]++;

        int required = need.size();   // Number of distinct characters needed
        int formed = 0;               // Number of characters whose required frequency is met

        unordered_map<char, int> window;

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {

            char c = s[r];
            window[c]++;

            // If this character's required frequency is satisfied
            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try shrinking the window
            while (formed == required) {

                // Update the minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char left = s[l];
                window[left]--;

                // Window is no longer valid
                if (need.count(left) && window[left] < need[left])
                    formed--;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};