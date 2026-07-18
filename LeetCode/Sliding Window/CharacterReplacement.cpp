class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();
        int maxf = 0;
        int K = k;
        vector<int> f(26, 0);
        for(; r < n; r++){
            f[s[r] - 'A']++;

            maxf = max(maxf, f[s[r] - 'A']);
            while((r-l+1) - maxf > k){
                f[s[l] - 'A']--;
                l++;
            }
        }
        return r-l;
    }
};