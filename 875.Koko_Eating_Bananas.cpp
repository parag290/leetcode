/**
 * 
 * Leetcode : https://leetcode.com/problems/koko-eating-bananas/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * Explaination : using binary search
 * 
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = high; // setting result to highest possible speed

        while(low <= high){
            int mid = low + (high-low)/2;
            long hours = 0;
            for(auto bananas : piles){
                hours += (bananas/mid) + (bananas%mid !=0);
            }

            if(hours <= h) {
                high = mid-1;
                result = mid;   // storing answer here as we do not have break condition
            } else {
                low = mid+1;
            }
        }

        return result;
    }
};