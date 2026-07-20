class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> f;
        int l = 0, sum = 0, n = s.size();

        for(int r = 0; r < n; r++){
            f[s[r]]++;

            while(f.size() == 3){
                sum += n - r;
                f[s[l]]--;
                if(f[s[l]] == 0) f.erase(s[l]);
                l++;
            }
        }
        return sum;
    }
};