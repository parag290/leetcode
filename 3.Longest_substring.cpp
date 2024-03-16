// Time Complexity : O(n)             
// Space Complexity : O(n) 
//

/*
Leet code : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Given a string s, find the length of the longest 
substring
 without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        int result = 0;
        int ptr = -1;
        unordered_map<char, int>cMap;

        for(int i=0; i<S.size(); i++){
            if(cMap.find(S[i]) != cMap.end()){
                ptr = max(cMap[S[i]], ptr);
            }
            result = max(result, i-ptr);
            cMap[S[i]] = i;
        }
        return result;

    }
};
