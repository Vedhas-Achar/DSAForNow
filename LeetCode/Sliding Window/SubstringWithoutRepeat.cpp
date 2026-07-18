class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> f(128, 0);
        int n = s.size();
        int l = 0, r = 0;
        int m = 0;
        for(; r < n; r++){
            f[s[r]]++;
            while(f[s[r]] > 1){
                f[s[l]]--;
                l++;
            }
            m = max(m, r-l+1);
        }
        return m;
    }
};