
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> vaca(n, vector<int>(3));
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < 3; j++) cin >> vaca[i][j];
	}

	vector<vector<int>> dp(n, vector<int>(3, 0));
	dp[0] = vaca[0];

	for(int i = 1; i < n; i++){
	    dp[i][0] = vaca[i][0] + max(dp[i-1][1], dp[i-1][2]);
	    dp[i][1] = vaca[i][1] + max(dp[i-1][0], dp[i-1][2]);
	    dp[i][2] = vaca[i][2] + max(dp[i-1][0], dp[i-1][1]);
	}
	
	cout << *max_element(dp[n-1].begin(), dp[n-1].end());
}
