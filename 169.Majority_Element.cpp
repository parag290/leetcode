/**
 * 
 * Leetcode : https://leetcode.com/problems/majority-element/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * Time complexity : O(n)
 * 
 * 
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int>freqMap;
        int size = nums.size();

        for(int i=0; i<size; i++){
            if(freqMap.find(nums[i]) != freqMap.end()){
                freqMap[nums[i]]++;
                if(freqMap[nums[i]] > size/2) return nums[i];
            } else {
                freqMap[nums[i]] = 1;
            }
        }

        return nums[0];
    }
};