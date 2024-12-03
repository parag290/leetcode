/**
 * 
 * Leetcode : https://leetcode.com/problems/design-a-leaderboard/description/
 * 
 * heap is implemented using priority queue.
 * Refer leetcode for simplere explaination  374.Top_K_Frequent_Element
 * 
 * 
*/

class Leaderboard {
    unordered_map<int, int>hMap;

public:
    Leaderboard() {
    }
    
    void addScore(int playerId, int score) {
        if(hMap.find(playerId) != hMap.end()){
            hMap[playerId] += score;
        } else {
            hMap[playerId] = score;
        }
    }
    
    int top(int K) {

        int result = 0;

        auto comp = [&](int n1, int n2){
            return hMap[n1] < hMap[n2];
        };
        priority_queue<int, vector<int>, decltype(comp)>heap(comp);
        for(auto &pair : hMap){
            heap.push(pair.first);

        }

        while(K){
            result += hMap[heap.top()];
            heap.pop();
            K--;
        }

        return result;
    }
    
    void reset(int playerId) {
        hMap[playerId] = 0;
    }
};
