class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    unordered_map<string,int> m;
    string helper(Node* root){
        if(root == NULL){
            return "$";
        }
        if(root->left == NULL && root->right == NULL){
            // as hume size 2 or more chahiye to isko map mei store 
            // krne ki zarurat nhi hai
            return to_string(root->data);
        }   
        
        string lans = helper(root->left);
        string rans = helper(root->right);
        
        string ans = to_string(root->data);
        ans += lans;
        ans += rans;
        
        m[ans]++;
        
        return ans;
    }
    
    int dupSub(Node *root) {
        if(root == NULL){
            return 0;
        }
        
        m.clear();
        helper(root);
        
        for(auto p: m){
            if(p.second > 1){
                return true;
            }
        }
        
        return false;
    }
};