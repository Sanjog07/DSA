    
    // APNA SOLUTION -> INSPIRED FROM BABBAR WALA SOLUTION
    // BSS THODA APNE TAREEKE SE LIKHA HAI THODE SE CHANGES KRKE
    
    bool helper(Node *root, int &k, int node, int &ans, bool &flag){
        if(root == NULL){
            return false;
        }
        if(root->data == node){
            flag = true;
            return true;
        }
        
        bool lans = helper(root->left, k, node ,ans, flag);
        bool rans = helper(root->right, k, node ,ans, flag);
        
        if(lans && !rans){
            k--;
            if(k == 0){
                ans = root->data;
                return false;
            }
            return true;
        }
        if(!lans && rans){
            k--;
            if(k == 0){
                ans = root->data;
                return false;
            }
            return true;
        }
        
        return false;
    }
    
    
    int kthAncestor(Node *root, int k, int node){
        if(root == NULL){
            return -1;
        } 
        
        // bss ek case ka acche se dhyaan rkhna 
        // where kth ancestor exist hi nhi krta
        // i.e k is large -> then ans == -1
        
        bool flag = false;
        int ans = INT_MAX;
        
        helper(root, k, node, ans, flag);
        
        // and ye check kr rha hai ki target node exist or not
        if(!flag){
            return 0;
        }
        
        
        return (ans == INT_MAX) ? -1 : ans;
    }



    // BABBAR -> https://www.youtube.com/watch?v=QG0hE0R_ng4&t=2714s
    // Code -> 
    Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);

    // ye ans->data == node -> vo wala case hai 
    // jb kth ancestor exist hi nhi krta i.e k is large

    // and ans == NULL -> i.e target doesn't exist
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

//  BASIC APPROACH

vector<int> path;

bool helper(Node *root,int node){
    if(root == NULL){
        return false;
    }
    
    path.push_back(root->data);
    if(root->data == node){
        return true;
    }
    
    bool l = helper(root->left,node);
    bool r = helper(root->right,node);
    
    if(l || r){
        return true;
    }
    
    path.pop_back();
    
    return false;
}

int kthAncestor(Node *root, int k, int node){
    path.clear();
    if(root == NULL){
        return -1;
    }
    
    bool ans = helper(root, node);
    if(!ans){
        return -1;
    }
    
    int n = path.size();
    // cout<<n<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<path[i]<<" ";
    // }
    // cout<<endl;
    if(k >= n){
        return -1;
    }
    
    return path[n-k-1];
}