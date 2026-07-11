
#include <bits/stdc++.h>
using namespace std;

int frog(vector<int>& nums, vector<int>& dp, int i){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    
    int prev1 = frog(nums, dp, i-1) + abs(nums[i] - nums[i-1]);
    int prev2 = INT_MAX;
    if(i > 1) prev2 = frog(nums, dp, i-2) + abs(nums[i] - nums[i-2]);
    
    return dp[i] = min(prev1, prev2);
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    vector<int> dp(n, -1);
    dp[n] = 0;
    
    cout << frog(nums, dp, n-1);
}