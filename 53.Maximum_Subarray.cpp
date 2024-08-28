/**
 * 
 * https://leetcode.com/problems/maximum-subarray/description/
 * 
*/

/**
 * Using running sum method 
 * 
 * maSum will keep the track of maximum sum
 * 
 * Whenever currentSum becomes negatiev, there is not point in keeping that sum, therefore
 * reset currentSum to zero
 * 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for(int i=0; i<nums.size(); i++){
            currentSum = currentSum + nums[i];
            maxSum = std::max(currentSum, maxSum);

            if(currentSum < 0){
                currentSum = 0;
            }
        }

        return maxSum;
    }
};