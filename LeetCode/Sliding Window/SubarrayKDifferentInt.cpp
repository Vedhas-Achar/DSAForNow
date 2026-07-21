class Solution {
public:

    int atmost(vector<int>& nums, int k){
        unordered_map<int, int> f;
        int l = 0, res = 0;
        for(int r = 0; r < nums.size(); r++){
            f[nums[r]]++;

            while(f.size() > k){
                f[nums[l]]--;
                if(f[nums[l]] == 0) f.erase(nums[l]);
                l++;
            }
            res += r-l+1;
        }
        return res;  
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};