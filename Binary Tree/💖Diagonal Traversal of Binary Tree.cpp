vector<int> diagonal(Node *root){
    if(root == NULL){
        return {};
    }
    vector<int> ans;
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        
        while(temp != NULL){
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    
    return ans;
}