/**
 * 
 * Leetcode = https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
*/



class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int>q;
        for(int i=0; i<students.size(); i++){
            q.push(students[i]);
        }

        int lastServed = 0;
        int idx = 0;
        while(!q.empty() && lastServed < q.size()){
            int student = q.front();
            q.pop();
            if(sandwiches[idx] == student){
                idx++;
                lastServed = 0;
            } else {
                q.push(student);
                lastServed++;
            }
        }

        return q.size();
    }
};