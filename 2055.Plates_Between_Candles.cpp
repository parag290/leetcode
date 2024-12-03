/*
This question was given in Amazon interview 

Leetcode : https://leetcode.com/problems/plates-between-candles/description/

There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.
You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.
For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.

*/


/*
Approach 1 : Simple Solution : Time limit exccedded

*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        vector<int>result;
        for(auto q : queries){
            result.push_back(helper(s, q[0], q[1]));
        }
        return result;
    }

    int helper(string s, int start, int end){
   
        vector<bool>data(s.size(), true);
        int count = 0;

        int i = start;
        while(i<=end && s[i]!= '|'){
            data[i] = false;
            i++;
        }

        i = end;
        while(i>=start && s[i]!= '|'){
            data[i] = false;
            i--;
        }

        for(int i=start; i<=end; i++){
            if(s[i] == '*' && data[i] == true){
                count++;
            }
        }
        return count;
    }
};






