class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        for(int x: cardPoints) total += x;
        int n = cardPoints.size();
        if(k == n) return total;

        int wSum = 0;
        for(int i = 0; i < n-k; i++) wSum += cardPoints[i];

        int minW = wSum;
        for(int i = n - k; i < n; i++){
            wSum += cardPoints[i];
            wSum -= cardPoints[i - (n-k)];
            minW = min(minW, wSum);
        }
        return total - minW;
    }
};