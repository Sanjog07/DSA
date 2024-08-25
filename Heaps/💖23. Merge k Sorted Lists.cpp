/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// https://leetcode.com/problems/merge-k-sorted-lists/discuss/1880633/CPP-MINHEAP-EASY-EXPLANATION

typedef pair<int,ListNode*> pii;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int k = arr.size();
        if(k == 0){
            return NULL;
        }
        
        ListNode* ans;
        
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        for(int i=0; i<k; i++){
            ListNode* temp = arr[i];
            if(temp != NULL){ // ye yaad se check kr lena bcz empty lists bhi ho skti hai
                pq.push({temp->val, temp});
            }
        }
        
        if(pq.empty()){
            return NULL;
        }
        
        auto it = pq.top();
        pq.pop();
        ans = it.second;
        if((it.second)->next != NULL){
            pq.push({(it.second)->next->val, (it.second)->next});
        }   
        
        ListNode* temp = ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            temp->next = it.second;
            temp = temp->next;
            
            if((it.second)->next != NULL){
                pq.push({(it.second)->next->val, (it.second)->next});
            }
        }
        
        return ans;
    }
};