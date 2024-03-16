/*
Leet code : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

Find All Duplicates in an Array

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/

/*
Apporach 1 : using hashset to store number 
// Time Complexity : O(n)  ...           
// Space Complexity : O(n) ... due to use of hashset
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::unordered_set<int>hSet;
        std::vector<int>result;

        for(int i=0; i<nums.size(); i++){
            if(hSet.find(nums[i]) == hSet.end()){
                hSet.insert(nums[i]);
            } else {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};


/*
Approach 2 : modifying same array 
// Time Complexity : O(n)  ...           
// Space Complexity : O(1)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int>result;

        for(int i=0; i<nums.size(); i++){
            int idx = std::abs(nums[i]) - 1;
            if(nums[idx] < 0){
                result.push_back(std::abs(nums[i]));
            } else {
                nums[idx] *= -1;
            }
        }
        return result;
    }
};
