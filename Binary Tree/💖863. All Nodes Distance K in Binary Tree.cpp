class Solution {
    
    vector<int> ans;
    
    void printKdown(TreeNode* root,int k){
        if(root == NULL || k < 0){
            return;
        }
        if(k == 0){
            ans.push_back(root->val);
        }
        
        printKdown(root->left, k-1);
        printKdown(root->right, k-1);
        
        return;
    }
    
    // ye wala fnc dega dist of root from tar
    int nodeAtDistK(TreeNode* root, TreeNode* tar, int k){
        if(root == NULL){
            return -1;
        }
        if(root == tar){
            printKdown(root, k);
            return 0;
        }
        
        //so ye wala fnc dega dist of root->left from tar
        int l = nodeAtDistK(root->left, tar, k);
        if(l != -1){
            if((l+1) == k){
                ans.push_back(root->val);
            }else{
                
                // yha pe printKdown(root, (k-l-1));
                // ye cheez isliye nhi li bcz humko 
                // ab sirf right wali nodes print krni hai
                // and upar wale fnc se left wali bhi 
                // print ho jaati
                
                printKdown(root->right, (k-l-2));
            }
            
            return l+1;
        }
        
        int r = nodeAtDistK(root->right, tar, k);
        if(r != -1){
            if((r+1) == k){
                ans.push_back(root->val);
            }else{
                printKdown(root->left, (k-r-2));
            }
            
            return r+1;
        }  
        
        return -1;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
        nodeAtDistK(root, tar, k);
        
        return ans;
    }
};