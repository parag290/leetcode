/**
 * 
 * Leetcode : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>hMap;

        for(int i=0; i<numbers.size();i++){
            int toFind = target - numbers[i];
            if(hMap.find(toFind) != hMap.end()){
                return {hMap[toFind]+1, i+1};
            } else {
                hMap[numbers[i]] = i;
            }
        }
        return {-1,-1};
    }
};