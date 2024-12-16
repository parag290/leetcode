/**
 * 
 * Leetcode : https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * 
*/

/**
 * 
 * Approach 1 : using sorting
 * 
 * Time complexity = O(nLogn)
 * 
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int currentLen = 1;
        for(int i=0; i<nums.size()-1; i++){

            if(nums[i] == nums[i+1]) continue;

            if(nums[i] + 1 == nums[i+1]){
                currentLen++;
                maxLen = std::max(currentLen, maxLen);
            } else {
                currentLen = 1;
            }
        }
        return maxLen;
    }
};

/**
 * 
 * Approach 2 : Using hash set
 * 
 * Time complexity : O(n)
 * 
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>hSet(nums.begin(), nums.end());
        int maxLen = 0;

        for(auto num : hSet) {
            if(hSet.find(num - 1) == hSet.end()){
                int currentLen = 1;
                int currentNum = num;
                while(hSet.find(currentNum+1) != hSet.end()){
                    currentNum++;
                    currentLen++;
                }
                maxLen = std::max(currentLen, maxLen);
            }
        }

        return maxLen;
    }
};