/**
 * 
 * Leetcode = https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days
 * 
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
*/

/**
 * 
 * Approach 1 : Store all elements in an array. Sort the array and create new linked list with sorted array
 * 
 * Time complexity = O(n) + O(nlogn) + O(n) == O(n) + O(nlogn)
 * where n is the total number of elements in all lists 
 * ..... O(n) for storing all elements in the vector and creating new list
 * ..... O(nlogn) ... for sorting the vector
 * 
*/ 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>storage;

        for(auto list : lists){
            while(list){
                storage.push_back(list->val);
                list = list->next;
            }
        }

        sort(storage.begin(), storage.end());
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        for(auto data : storage){
            ptr->next = new ListNode(data);
            ptr = ptr->next;
        }

        return head->next;
        
    }
};


/**
 * 
 * Approach 2 : Use priority Queue to store the elements
 * 
 * Time complexity = O(n) + O(logn)
 * ..... where n is the total number of elements in all lists 
 * ..... O(n) for storing all elements in heap (priority_queue>) and creating new list
 * ..... O(logn) for inserting the node in priority_queue
 *
 * 
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto comp = [&](ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>q(comp);

        for(auto node : lists){
            while(node){
                q.push(node);
                node = node->next;
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* ptr = head;

        while(!q.empty()){
            ListNode* temp = q.top();
            q.pop();
            ptr->next = new ListNode(temp->val);
            ptr = ptr->next;
        }
        return head->next;
    }
};