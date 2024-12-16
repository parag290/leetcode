/**
 * 
 * Leetcode : https://leetcode.com/problems/jump-game/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * 
 * Explaination :  Greedy Algorithm
 * 

Understanding the Solution: A Greedy Approach
The provided solution employs a greedy approach to determine if a player can reach the last index of the given array. The idea is to start from the last index and work backward, checking if any index can reach the last index.

Key Points:

lastPos: This variable keeps track of the farthest reachable index from the current position.
Iterating Backward:
We iterate through the array from the last index to the first index.
For each index i, we check if it can reach the lastPos.
Updating lastPos:
If i + nums[i] >= lastPos, it means we can reach the lastPos from index i.
We update lastPos to i as it becomes the new farthest reachable point.
Checking the Initial Position:
After iterating through the entire array, if lastPos is 0, it means we can reach the last index from the initial position.
Why This Approach Works:

Greedy Choice: At each step, we make a greedy choice by selecting the farthest reachable index.
Optimal Substructure: The problem can be broken down into smaller subproblems, where reaching a certain index is a prerequisite for reaching the final index.
Time Complexity: O(N)

We iterate through the array once, making each iteration constant time.
Space Complexity: O(1)

We use a constant amount of extra space.
By iterating backward and updating the lastPos greedily, this solution efficiently determines whether the player can reach the end of the array.

 * 
 * 
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size()-1;

        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] + i >= lastPos){
                lastPos = i;
            }
        }
        return lastPos == 0;
    }

};