class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;
        int l = 0, ans = 0;

        for(int r = 0; r < fruits.size(); r++){
            f[fruits[r]]++;
            
            while(f.size() > 2){
                f[fruits[l]]--;
                if(f[fruits[l]] == 0) f.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};