class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = 0;
        int K = k;
        int l = 0, r = 0, n = nums.size();
        for(r = 0; r < n; r++){
            if(nums[r] == 0 && K > 0) K--;

            else if(nums[r] == 0 && K == 0){
                ans = max(ans, r-l);
                while(nums[l] == 1) l++;
                l++;
                
            }
        }

        return max(ans, r-l);
    }
};