class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> f;
        int l = 0, ans = -1, n = s.size();
        
        for(int r = 0; r < n; r++){
            f[s[r]]++;
            
            while(f.size() > k){
                f[s[l]]--;
                if(f[s[l]] == 0){
                    f.erase(s[l]);
                }
                l++;
            }
            if(f.size() == k) ans = max(ans, r-l+1);
        }
        return ans;
        
    }
};