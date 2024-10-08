class Solution{
    
    Node* head;
    Node* prev = NULL;
    
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* bToDLL(Node *root){
        if(root == NULL){
            return NULL;
        }
        
        bToDLL(root->left);
        if(prev == NULL){
            head = root;
        }else{
            root->left = prev;
            prev->right = root;
        }
        
        prev = root;
        bToDLL(root->right);
        
        return head;
    }
};
