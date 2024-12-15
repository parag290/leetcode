/**
 * 
 * Leetcode : https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * 
*/

class Solution {
    unordered_map<Node*, Node*>hMap;
public:
    Node* copyRandomList(Node* head) {
        Node* dummyHead = new Node(-1);
        Node* newPtr = dummyHead;
        Node* ptr = head;

        while(ptr != nullptr){
            newPtr->next = new Node(ptr->val);
            hMap[ptr] = newPtr->next;
            ptr = ptr->next;
            newPtr = newPtr->next;
        }

        ptr = head;
        newPtr = dummyHead->next;
        while(ptr != nullptr){
            newPtr->random = hMap[ptr->random];
            ptr = ptr->next;
            newPtr = newPtr->next;
        }

        return dummyHead->next;
        


    }
};