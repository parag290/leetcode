/**
 * 
 * Leetcode : https://leetcode.com/problems/add-two-integers/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * Explaination : use chatgpt or gemini
 * 
*/

class Solution {
public:
    int sum(int num1, int num2) {
        int carry = 0;

        while(num2){
            carry = num1 & num2;
            num1 = num1 ^ num2;
            num2 = carry << 1;
        }

        return num1;
        
    }
};