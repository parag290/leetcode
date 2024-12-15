/**
 * 
 * Leetcode : https://leetcode.com/problems/maximum-matrix-sum/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * 
 * Read editorial for explaination
 * 
*/



class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long curSum = 0;
        int lowestNum = INT_MAX;
        int negativeCount = 0;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                curSum += std::abs(matrix[i][j]);

                if(matrix[i][j] < 0){
                    negativeCount++;
                }
                lowestNum = std::min(lowestNum, std::abs(matrix[i][j]));    
            }
        }


        if(negativeCount%2 != 0){
            curSum -= (lowestNum * 2);
        }

        return curSum;

    }
};