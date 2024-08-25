vector<int> leftView(Node *root){
    if(root == NULL){
        return vector<int>();
    }
    vector<int> ans;
    list<Node*> q;
    q.push_back(root);
    
    while(!q.empty()){
        Node* left = q.front();
        ans.push_back(left->data);
        
        int x = q.size();
        for(int i=0; i<x; i++){
            Node* node = q.front();
            q.pop_front();
            
            if(node->left){
                q.push_back(node->left);
            }
            if(node->right){
                q.push_back(node->right);
            }
        }
    }
    return ans;    
}




    vector<int> ans;
    int ml = INT_MIN;
    
    void helper(Node *root, int cl){
        if(root == NULL){
            return;
        }
        
        if(cl > ml){
            ans.push_back(root->data);
            ml = cl;
        }
        
        helper(root->left, cl+1);
        helper(root->right, cl+1);
        
        return;
    }
    
    vector<int> leftView(Node *root){
        helper(root, 0);
        
        return ans;
    }