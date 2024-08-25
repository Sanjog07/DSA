class Solution {
    
    unordered_map<string, pair<int, TreeNode*>> m;
    
    string helper(TreeNode* root){
        if(root == NULL){
            return "$";
        } 
        if(root->left == NULL && root->right == NULL){
            string ans = to_string(root->val);
            m[ans].first++;
            m[ans].second = root;
            
            return ans;
        }   
        
        string lans = helper(root->left);
        string rans = helper(root->right);
        
        // [2,1,11,11,null,1] see this case iss case mei gfg wale ques 
        // ki approach thodi si change krni pdegi
        
        // string ans = to_string(root->val);
        // ans += lans;
        // ans += rans;
        
        string ans = to_string(root->val);
        ans += "#";
        ans += (lans + "#");
        ans += (rans + "#");   
        
        // i.e hum yha pe hr value ke baad ek deliminator lga rhe hai
        // so that kisi bhi tarekke se 2 alag cases mei same string na
        // bn ske
        
        m[ans].first++;
        m[ans].second = root;
        
        return ans;        
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        
        vector<TreeNode*> res;
        
        m.clear();
        helper(root);
        
        for(auto tri: m){
            if(tri.second.first > 1){
                res.push_back(tri.second.second);
            }
        }
        
        return res;
    }
};