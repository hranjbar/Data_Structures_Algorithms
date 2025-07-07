/*
You are given an array prices where prices[i] is the price of 
a given stock on the ith day, and an integer fee representing 
a transaction fee.
Find the maximum profit you can achieve. You may complete as 
many transactions as you like, but you need to pay the 
transaction fee for each transaction.
Note:
You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock
purchase and sale.

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 
Constraints:
1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<pair<int, int>> dp(prices.size(), {0,0});
        dp.front().first = 0 - prices.front();
        // dp elements = {have the stock, don't have the stock}
        for (int i = 1; i < prices.size(); i++){
            // 1. max of {you had it and now you keep it, you din't have it and now you buy it}
            dp[i].first = max(dp[i - 1].first, dp[i - 1].second - prices[i]);
            // 2. max of {you had it and now you sell it, you didn't have it and still don't buy it now}
            dp[i].second = max(dp[i - 1].first + prices[i] - fee, dp[i - 1].second);
        }
        return max(dp.back().first, dp.back().second);
    }
};
