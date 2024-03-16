/*
Leetcode : https://leetcode.com/problems/palindrome-number/description/

Given an integer x, return true if x is a palindrome, and false otherwise.
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/


// Approach 1 : Convert int to string and check for palindrom

    bool isPalindrome(int x) {
        if(x<0) return false;
        string temp = to_string(x);

        int size = temp.size();
        for(int i=0; i<=size/2; i++){
            if(temp.at(i) != temp.at(size-1-i)) return false;
        }
        
        return true;
    }

// Approach 1 : reverse the number and check if original number is same as resevered

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int tmp = x;
        long reverse= 0;

        while(tmp){
            reverse = reverse*10 + tmp%10;
            tmp = tmp/10;
        }
        
        return reverse == x;
    }
};
