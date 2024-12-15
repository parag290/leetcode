/**
 * 
 * Leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a 
 * different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. 
 * If you cannot achieve any profit, return 0.
 * 
*/

/**
 * Time complexity = O(n)
 * 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;

        for(int i=0; i<prices.size(); i++){
            minPrice = std::min(prices[i], minPrice);
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};