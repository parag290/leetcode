// Time Complexity : O(n)             
// Space Complexity : O(n) 
//

/*
Leet code : https://leetcode.com/problems/zigzag-conversion/description/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
*/

/*
Explaination : Using direction flag to decide operation.
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>matrix(numRows, "");
        string result ="";
        int dir = 1;
        int j = 0, i = 0;

        while(i<s.size()){
            if(dir){
                while(i<s.size() && j<matrix.size()){
                    matrix[j] += s[i];
                        j++;
                        i++;
                }
                j -= 2;
                dir = 0;
            } else {
                while(i<s.size() && j>=0){
                    matrix[j] += s[i];
                    j--;
                    i++;
                }
                j += 2;
                dir = 1;
            }
        }

        for(auto &str : matrix){
            result += str;
        }

        return result;
    }
};