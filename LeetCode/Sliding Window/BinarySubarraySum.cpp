class Solution {
public:

    int AtMost(vector<int>& nums, int goal){
        int l = 0, sum = 0, res = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum > goal && l <= r){
                sum -= nums[l];
                l++;
            }
            res += r-l+1;
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return AtMost(nums, goal) - AtMost(nums, goal - 1);
    }
};