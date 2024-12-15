/**
 * 
 * Leetcode : https://leetcode.com/problems/next-permutation/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * Explaination : read editorial example
 * 
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int ptr = nums.size()-2;

        while(ptr>=0 && nums[ptr]>=nums[ptr+1]){
            ptr--;
        }
        if(ptr >= 0){
            int i = nums.size()-1;
            while(nums[i]<=nums[ptr]){
                i--;
            }
            swap(nums[ptr], nums[i]);
        }
        reverse(nums.begin()+ptr+1, nums.end());
    }
};