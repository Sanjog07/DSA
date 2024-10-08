class Solution {
    
    
    TreeNode* helper(vector<int>& nums, int s,int e){
        if(s > e){
            return NULL;
        }
        
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = helper(nums, s, mid-1);
        root->right = helper(nums, mid+1, e);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        TreeNode* ans = helper(nums, 0, n-1);
        
        return ans;
    }
};