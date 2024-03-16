/**
 * 
 * https://leetcode.com/problems/contains-duplicate/
 * 
 * 
*/



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int>hSet;

        for(int i=0; i<nums.size(); i++){
            if(hSet.find(nums[i]) != hSet.end()){
                return true;
            } else {
                hSet.insert(nums[i]);
            }
        }
        return false;
    }
};