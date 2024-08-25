class Solution{

    unordered_map<int,int> m;
    int cnt = 0;

    void solve(Node* root){
        if(root == NULL){
            return;
        }
        
        m[root->data] = 1;
        solve(root->left);
        solve(root->right);
        
        return;
    }
    
    void helper(Node* root,int x){
        if(root == NULL){
            return;
        }
        
        int val = root->data;
        if(m.find(x - val) != m.end()){
            cnt++;
        }
        
        helper(root->left, x);
        helper(root->right, x);
        
        return;
    }

public:
    int countPairs(Node* root1, Node* root2, int x){
        if(root1 == NULL || root2 == NULL){
            return 0;
        }
        
        solve(root2);
        helper(root1, x);
        
        return cnt;
    }
};