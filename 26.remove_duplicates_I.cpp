// Time Complexity : O(n)             
// Space Complexity : O(1) 
//
/*
Leet code : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. 
Then return the number of unique elements in nums.
*/


/*
Approach 1 : Not using extras space
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0;
        for (int i=1; i<nums.size(); i++){
            if(nums[ptr] != nums[i]){
                ptr++;
                nums[ptr] = nums[i];
            }
        }

        return ptr+1;
    }
};