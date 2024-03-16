/*

Leetcode : https://leetcode.com/problems/sum-of-distances/description/
You are given a 0-indexed integer array nums. 
There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| 
over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
*/

/*
Approach 1 : 

This has issue with time limit excceded
*/


class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        vector<long long>result(nums.size(), 0);
        unordered_map<int, vector<int>>hMap;

        for(int i=0; i<nums.size(); i++){
            hMap[nums[i]].push_back(i);
        }

        for(auto &pair : hMap){
            int size = pair.second.size();
            if(size > 1){
                for(int ptr = 0; ptr<size; ptr++){
                    std::swap(pair.second[0], pair.second[ptr]);
                    long long sum = 0;
                    for(int i=1; i<size; i++){
                        sum += std::abs(pair.second[0] - pair.second[i]); 
                    }
                    result[pair.second[0]] = sum;
                }
            }
        }

        return result;
    }
};