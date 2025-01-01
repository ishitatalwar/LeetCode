class Solution {
public:
    // Brute force approach
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0;
        int mini = prices[0];
        for(int i = 0 ; i<n; i++){
            maxPro = max(prices[i]-mini, maxPro);
            mini = min(prices[i], mini);
        }
        return maxPro;
    }
};