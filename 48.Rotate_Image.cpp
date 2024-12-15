/**
 * 
 * Leetcode : https://leetcode.com/problems/rotate-image/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * Explaination : read editorial
 * 
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // rotate diagoanally first
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // swap columns now
        for(int row=0; row<n; row++){
            for(int col=0; col<n/2; col++){
                swap(matrix[row][col], matrix[row][n-col-1]);
            }
        }
    }
};