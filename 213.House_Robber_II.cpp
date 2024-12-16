/**
 * 
 * Leetcode : https://leetcode.com/problems/house-robber-ii/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * Explaination : Dynamic progamming modification for house robber problem
 * Assume we have nums of [7,4,1,9,3,8,6,5]
 * 
 * if robber decides to rob first house (7) then he can not rob last house (5) because
 * in cicular arrangement they are adjucant houses.
 * Therefore our house set can be reduced to - [7,4,1,9,3,8,6]
 * 
 * And if robber decides to rob last house; then we need not to consider first house.
 * Therefore our house set can be reduced to - [4,1,9,3,8,6,5]
 * 
 * Now, this problem is simplified to basic House robber problem with two sets of houses.
 * We will calculate maximum amount in both cases and elect maximum out of both.
 * 
*/


class Solution {
public:
    int rob(vector<int>& nums) {

        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        int max1 = simpleRobberDp(nums, 0, nums.size()-2);
        int max2 = simpleRobberDp(nums, 1, nums.size()-1);

        return std::max(max1, max2);
    }

    int simpleRobberDp(vector<int>&nums, int start, int end){
        vector<int>dp(nums.size()+1, 0);

        for(int i=start, j=2; i<=end; i++, j++){
            dp[j] = std::max(dp[j-1], dp[j-2] + nums[i]);
        }

        return dp[nums.size()];

    }
};

