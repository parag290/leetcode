/**
 * 
 * https://leetcode.com/problems/length-of-last-word/description/
 * 
*/

// Approach 1

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;

        istringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        return words.back().size();
    }
};


// Approach 2

class Solution {
public:
    int lengthOfLastWord(string s) {
        int p = s.length()-1;

        //remove trailing space
        while(p !=0 && s[p] == ' ') {
            p--;
        }
        //count length of last word
        int len = 0;
        while(p>=0 && s[p] != ' '){
            p--;
            len++;
        }
        return len;

    }
};

