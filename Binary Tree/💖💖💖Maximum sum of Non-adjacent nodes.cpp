


// https://www.youtube.com/watch?v=ZdIrKO7gqok


// This is a Knapsack kind of problem 
// so we'll use DP
// yha pe bhi hr node pe hmare pass choice hai ki 
// usko le ya na le


// Top-Down Approach

class Solution{
    
    unordered_map<Node*,int> dp;
    
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root){
        if(root == NULL){
            return 0;
        }
        if(dp.find(root) != dp.end()){
            return dp[root];
        }
        
        int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
        if(root->left){
            ans1 = getMaxSum(root->left->left);
            ans2 = getMaxSum(root->left->right);
        }
        if(root->right){
            ans3 = getMaxSum(root->right->left);
            ans4 = getMaxSum(root->right->right);
        }      
        
        // include the current node
        int inc = root->data + ans1 + ans2 + ans3 + ans4;
        
        int exc = getMaxSum(root->left) + getMaxSum(root->right);
        
        return dp[root] = max(inc, exc);
    }
};


//Bottom - Up Approach

typedef pair<int,int> pii;

class Solution{
    
    pii helper(Node* root){
        pii p; // .first = include and .second = exclude
        if(root == NULL){
            p.first = 0;
            p.second  = 0;
            
            return p;
        }
        
        pii l = helper(root->left);
        pii r = helper(root->right);
        
        // we're including current node
        p.first = root->data + l.second + r.second;

        // we're excluding current node
        p.second = max(l.first, l.second) + max(r.first, r.second);
        
        return p;
        
    }
    
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        if(root == NULL){
            return 0;
        }
        
        pii ans = helper(root);
        
        return max(ans.first, ans.second);
    }
};