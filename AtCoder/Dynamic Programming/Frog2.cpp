
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	cin >> k;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];

	vector<int> dp(n, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) dp[i] = min(dp[i], dp[i - j] + abs(nums[i] - nums[i - j]));
		}
	}

	cout << dp[n - 1];
}