// Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> leftProfit(n, 0), rightProfit(n, 0);
        int mn = 2e9;
        for(int i = 0; i < n; i++) {
            leftProfit[i] = max(leftProfit[i], prices[i] - mn);
            mn = min(mn, prices[i]);
            if(i > 0) leftProfit[i] = max(leftProfit[i], leftProfit[i - 1]);
        }
        int mx = 0;
        for(int i = n - 1; i >= 0; i--) {
            rightProfit[i] = max(rightProfit[i], mx - prices[i]);
            mx = max(mx, prices[i]);
            if(i < n - 1) rightProfit[i] = max(rightProfit[i], rightProfit[i + 1]);
        }
        
        long long ans = leftProfit[n - 1];
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, (long long)leftProfit[i] + rightProfit[i + 1]);
        }
        return ans;
    }
};
