class Solution {
    
    int length(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        return len;
    }
    
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // hume just values swap krni hai
        // and not the complete nodes
        
        int len = length(head);
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        // Kth node form end will be (n-k+1)th node from starting
        int x = (len - k + 1); 
        
        k--;
        while(k--){
            temp1 = temp1->next;
        }
        
        x--;
        while(x--){
            temp2 = temp2->next;
        }  
        
        swap(temp1->val , temp2->val);
        
        return head;
    }
};