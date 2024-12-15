/**
 * 
 * Leetcode : https://leetcode.com/problems/climbing-stairs/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * 
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
*/


/**
 * 
 * Approach 1 : using DFS
 * 
*/

class Solution {
    int count = 0;
public:
    int climbStairs(int n) {
        dfs(n);
        return count;
    }

    void dfs(int n){
        if(n < 0) return;
        if(n == 0) {
            count++;
            return;
        }
        // step 1
        dfs(n-1);
        // step 2
        dfs(n-2);
    }
};

/**
 * 
 * Approach 2 : Dynamic programming
 * 
 * 
*/

class Solution {
    int count = 0;
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int>dp(n+1, 0);

        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};