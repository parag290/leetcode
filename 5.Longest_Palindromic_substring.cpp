// Time Complexity : O(n*m) ... n is number of characters in string
//                          ... m is size of maximum palindrome substring             
// Space Complexity : O(m)
//

/*
Leet code : https://leetcode.com/problems/longest-palindromic-substring/description/
*/

/*
Explaination : 
From each index, search is done on both left and right side to check if left and right characters
are same.
Array can be of odd or even size.
e.g. aba
     abba

Two times while loop is used to handle both scenarios.
*/


class Solution {
public:
    string longestPalindrome(string s) {

        string temp = "";
        string result = "";

        for(int i=0; i<s.size(); i++){
            int left=i, right = i;

            while(left>=0 && right<s.size() && s[left] == s[right]){
                temp = s.substr(left, right-left+1);
                left--;
                right++;
            }
            if(temp.size() > result.size()) result = temp;

            temp = "";
            left=i;
            right=i+1;

            while(left>=0 && right<s.size() && s[left] == s[right]){
                temp = s.substr(left, right-left+1);
                left--;
                right++;
            }
            if(temp.size() > result.size()) result = temp;

        }

        return result;
        
    }
};