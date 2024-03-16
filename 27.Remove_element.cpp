// Time Complexity : O(n)             
// Space Complexity : O(1) 
//

/*
Leet code : https://leetcode.com/problems/remove-element/description/

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. 
Then return the number of elements in nums which are not equal to val.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr;
    }
};